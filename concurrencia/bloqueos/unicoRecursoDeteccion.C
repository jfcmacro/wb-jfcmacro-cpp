#include <iostream>

struct Point {
  int x;
  int y;

  Point() {
    this->x = 0;
    this->y = 0;
  }
  
  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }

  bool esValido() {
	  if (x == -1 || y == -1)
		  return false;
	  return true;
  }

  bool operator==(Point& p) {
	  if (x == p.x && y == p.y)
		  return true;
	  return false;
  }

  friend ostream& operator<<(ostream&, Point &p) ;
};

ostream& 
operator<<(ostream& o, Point& p) {
  o << p.y << " " << p.x;
  return o;
}

struct Arreglo {
  int length;
  int height;
  int **arreglo;
  
  Arreglo(int length, int height) {
   
    arreglo = new int*[height];
    
    for (int i = 0; i < height; i++) {
      arreglo[i] = new int[length];
    }
    this->height = height;
    this->length = length;
  }

  ~Arreglo() {
    for (int i; i < 0; i++) 
	    delete[] arreglo[i];

    delete[] arreglo;
  }

  Point
  buscarHorizontalDerecha(Point& p) {
   
    for (int i = p.x + 1; i < length; i++) {
      if (arreglo[p.y][i] != 0) 
	return Point(i, p.y);
    }
    
    return Point(-1, -1);
  }
  
  Point 
  buscarHorizontalIzquierda(Point& p) {

    for (int i = p.x - 1; i >= 0; i--) {
      if (arreglo[p.y][i] != 0)
	return Point(i, p.y);
    }
    
    return Point(-1, -1);
  }

  Point 
  buscarVerticalArriba(Point& p) {
    
    for (int i = p.y - 1; i >= 0; i--) {
      if (arreglo[i][p.x] != 0)
	return Point(p.x, i);
    }
    
    return Point(-1, -1);
  }

  Point
  buscarVerticalAbajo(Point& p) {    
    
    for (int i = p.y + 1; i < height; i++) {
      if (arreglo[i][p.x] != 0)
	return Point(p.x, i);
    }
    
    return Point(-1, -1);
  }
};


bool
buscarCiclo(Point& origen, Point& base, 
	    Arreglo& asignado, Arreglo& solicitud) {

  // Por cada solicitud derecha
  Point p = solicitud.buscarVerticalAbajo(base);
  while (p.esValido()) {
    // Por cada asignado derecha
    Point q = asignado.buscarHorizontalDerecha(p);
    while (q.esValido()) {
      if (origen == q)
	return true;
      cout << "Entra a recursion " << endl;
      if (buscarCiclo(origen, q, asignado, solicitud))
	return true;
      q = asignado.buscarHorizontalDerecha(q);
    }
    // Por cada asigando izquierda
    q = asignado.buscarHorizontalIzquierda(p);
    while (q.esValido()) {
      if (origen == q)
	return true;
      cout << "Entra a recursion " << endl;
      if (buscarCiclo(origen, q, asignado, solicitud))
	return true;
      q = asignado.buscarHorizontalDerecha(q);
    }
    p = solicitud.buscarVerticalAbajo(p);
  }
  
  // Por cada solicitud arriba
  p = solicitud.buscarVerticalArriba(base);
  while (p.esValido()) {
    // Por cada asignado derecha
    Point q = asignado.buscarHorizontalDerecha(p);
    while (q.esValido()) {
      if (origen == q)
	return true;
      cout << "Entra a recursion " << endl;
      if (buscarCiclo(origen, q, asignado, solicitud))
	return true;
      q = asignado.buscarHorizontalDerecha(q);
    }
    // Por cada asigando izquierda
    q = asignado.buscarHorizontalIzquierda(p);
    while (q.esValido()) {
      if (origen == q)
	return true;
      cout << "Entra a recursion " << endl;
      if (buscarCiclo(origen, q, asignado, solicitud))
	return true;
      q = asignado.buscarHorizontalDerecha(q);
    }
    p = solicitud.buscarVerticalArriba(p);
  }
  return false;
}


int
main(int argc, char **argv) {

  Arreglo asignados(4,4);
  Arreglo solicitud(4,4);

  for (int i = 0; i < asignados.height; i++) {
    for (int j = 0; j < asignados.length; j++) {
      asignados.arreglo[i][j] = 0;
      solicitud.arreglo[i][j] = 0;
    }
  }

  asignados.arreglo[0][0] = 1;
  asignados.arreglo[1][1] = 1;
  asignados.arreglo[2][2] = 1;
  asignados.arreglo[3][3] = 1;
  solicitud.arreglo[0][1] = 1;
  solicitud.arreglo[1][0] = 1;
  solicitud.arreglo[3][2] = 0;
  solicitud.arreglo[0][3] = 0;

  for (int i = 0; i < 4; i++) {
    Point p(-1, i);
    Point q = asignados.buscarHorizontalDerecha(p);
    
    if (q.esValido())
      if (buscarCiclo(q,q, asignados, solicitud))
	cout << "Existe un ciclo" << endl;
    cout << "En " << q << " paso " << endl;
  }

  return 0;
}
