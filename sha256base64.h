#include <string>

std::string sha256(const std::string str);
std::string base64_encode(const std::string &in);
bool computeHash(const std::string& unhashed, std::string& hashed);
