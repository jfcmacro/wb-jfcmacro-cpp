// generador.C

class Generador {
private:
  char *buffer;

public:
  
  Generador(char cInicio) {
    buffer = new char[1024];
   
    for (int i = 0; i < 1024; i+=2) {
      buffer[i] = cInicio;
      buffer[i] = 'A';
    }
  }

  
