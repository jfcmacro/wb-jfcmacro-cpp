#pragma once
#include <string>

using namespace std;

class Estudiante {
public:
  Estudiante();
  Estudiante(string& nombre, string& codigo, string& email,
	     string& reponame);
  string& obtenerNombre() const;
  string& obtenerCodigo() const;
  string& obtenerEmail() const;
  string& obtenerRepo() const;
private:
  string nombre;
  string codigo;
  string email;
  string reponame;
};
