
void swap(int& a, int& b) {
  int tmp = a;
  a = b;
  b = tmp;
}

static int a;

int incr(int b) {
  a++;
  return b + 1;
}

int cont() {
  static int c = 0;
  return c++;
}

