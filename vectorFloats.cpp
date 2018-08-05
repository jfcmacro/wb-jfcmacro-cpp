#include <iostream>
#include <cstring>
#include <cstdlib>

const int buffer_size = 80;
char buffer[buffer_size];
const char* str1 = "1.2222, 2.2222, 3.2222, 4.2222, 5.2222, 6.2222, 7.2222, 8.2222";
const char* str2 = "1.22, 2.22, 3.22, 4.22, 5.22, 6.2222, 7.2222, -0.123";
void showBuffer();

int
main(void) {

  float ftemp[8];
  
  bcopy(str1,
        buffer, ::strlen(str1));

  showBuffer();
  
  char *pch = strtok(buffer, " ,");

  for (int i = 0; pch != nullptr && i < 16; ++i) {
    ftemp[i] = ::atof(pch);
    pch = strtok(NULL, " ,");
    std::cout << ftemp[i] << std::endl;
  }

  showBuffer();

  bcopy(str2,
        buffer, ::strlen(str2));

  pch = strtok(buffer, " ,");

  for (int i = 0; pch != nullptr && i < 16; ++i) {
    ftemp[i] = ::atof(pch);
    pch = strtok(NULL, " ,");
    std::cout << ftemp[i] << std::endl;
  }
  
  showBuffer();
  
  return EXIT_SUCCESS;
}

void showBuffer() {
  for (int i = 0; i < buffer_size; ++i) {
    std::cout << buffer[i] << std::endl;
  }
}
