#include "stdinfo.h"

Estudiante::Estudiante()
  : nombre(), codigo(),
    email(), reponame() { }

Estudiante::Estudiante(string& nombre,
                       string& codigo,
                       string& email,
                       string& reponame)
  : nombre(nombre),
    codigo(codigo),
    email(email),
    reponame(reponame) { }

string& Estudiante::obtenerNombre() const {

  return *(new string(nombre));
}

string& Estudiante::obtenerCodigo() const {

  return *(new string(codigo));
}

string& Estudiante::obtenerRepo() const {

  return *(new string(reponame));
}

string& Estudiante::obtenerEmail() const {
  return *(new string(email));
}
// void Estudiante::estRepoName() {

//   reponame += email.substr(0,email.find("@")-1);;
// }
