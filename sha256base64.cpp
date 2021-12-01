#include <iomanip>
#include <sstream>
#include <openssl/sha.h>
#include <openssl/evp.h>
#include "sha256base64.h"

std::string
sha256(const std::string str)
{
  unsigned char hash[SHA256_DIGEST_LENGTH];
  SHA256_CTX sha256;
  SHA256_Init(&sha256);
  SHA256_Update(&sha256, str.c_str(), str.size());
  SHA256_Final(hash, &sha256);
  std::stringstream ss;

  for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];

  return ss.str();
}

std::string
base64_encode(const std::string &in) {

  std::string out;

  int val = 0, valb = -6;
  for (unsigned char c : in) {
    val = (val << 8) + c;
    valb += 8;
    while (valb >= 0) {
      out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[(val>>valb)&0x3F]);
      valb -= 6;
    }
  }
  if (valb>-6) out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[((val<<8)>>(valb+8))&0x3F]);
  while (out.size()%4) out.push_back('=');
  return out;
}

bool
computeHash(const std::string& unhashed, std::string& hashed)
{
  bool success = false;

  EVP_MD_CTX* context = EVP_MD_CTX_new();

  if(context != NULL) {
    if(EVP_DigestInit_ex(context, EVP_sha256(), NULL)) {
      if(EVP_DigestUpdate(context, unhashed.c_str(), unhashed.length())) {
	unsigned char hash[EVP_MAX_MD_SIZE];
	unsigned int lengthOfHash = 0;

	if(EVP_DigestFinal_ex(context, hash, &lengthOfHash)) {
	  std::stringstream ss;
	  for(unsigned int i = 0; i < lengthOfHash; ++i)
	    {
	      ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
	    }

	  hashed = ss.str();
	  success = true;
	}
      }
    }

    EVP_MD_CTX_free(context);
  }

  return success;
}
