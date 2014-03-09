#define ACTION

int
#ifdef ACTION
main(int argc, char *argv[]) {
#else
main() {
#endif 

  int x;
  int y;

#ifdef ACTION
#ifndef INTRIGA
  x = 0;
  y = 1;
#else
  x = 1;
  y = 0;
#endif
#else
#ifdef	INTRIGA
  x = 0;
  y = 0;
#endif
  x = 1;
  y = 1;
#endif
}
