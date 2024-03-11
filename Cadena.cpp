
class Cadena {
  char *p;
  Cadena() {
    p = new char[0];
  }
  Cadena(const char *otra) {
    char *tmp = new [strlen(p) + strlen(otra)];
    // copy arreglo
    // copy arreglo 2
    delete p;
    p = tmp;
  }
