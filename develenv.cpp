#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>

const int  BUFFER_SIZE = 80;
const char GNOME_TERMINAL_PATH[] = "/usr/bin/gnome-terminal";
const char GNOME_TERMINAL[] = "gnome-terminal";
const char FULL_SCREEN_OPTION[] = "--full-screen";

bool existTmuxSession(const char* sname);

int
main(void) {

  pid_t child;
  
  if (existTmuxSession("devel:")) {

    child = fork();
    if (child == 0) {
      execl(GNOME_TERMINAL_PATH,
            GNOME_TERMINAL,
            "--command",
            "tmux attach -t devel",
            FULL_SCREEN_OPTION,
            NULL);
      exit(1);
    }
  }
  else {
    
    child = fork();

    if (child == 0) {
      execl(GNOME_TERMINAL_PATH,
            GNOME_TERMINAL,
            FULL_SCREEN_OPTION,
            "--window-with-profile",
            "Desarrollo Programas",
            NULL);
      exit(1);
    }
  }
  exit(0);
}

bool existTmuxSession(const char* sname) {
  FILE* pIn = popen("tmux ls", "r");
  char p[BUFFER_SIZE];
  char pFirst[BUFFER_SIZE];
  do {

    if (fgets(p, BUFFER_SIZE, pIn) == NULL) break;

    // std::cout << p << std::endl;
    
    sscanf(p, "%s", pFirst);

    // std::cout << "pFirst: " << pFirst << std::endl;
    
    if (::strcmp(pFirst, sname) == 0) return true;
  } while (true);

  return false;
}
