#include <unistd.h>
#include <cstdlib>

int
main(void) {

  pid_t child;

  child = fork();

  if (child == 0) {
    execl("/usr/bin/gnome-terminal",
          "gnome-terminal",
          "--full-screen",
          "--window-with-profile",
          "Desarrollo Programas",
          NULL);
    exit(1);
  }
  exit(0);
}
