/*
 * fichero: printEvalUnit.cpp
 * 
 * created: 2016-06-10
 *
 * programmer: Juan Francisco Cardona McCormick
 *
 * History of modifications:
 * 2016-06-10 - Start of modifications. This is the first version of the file
 */
#include <string>
#include <iostream>
#include <unistd.h>
#include "stdreposutils.h"

static void usage(const char* progname) {
  std::cerr << "Usage: " << progname << "<unitEvalFile>" << std::endl;
  ::_exit(1);
}

int
main(int argc, char **argv) {

  if (argc != 2) {

    usage(argv[0]);
  }

  std::string evalUnitFile(argv[1]);

  EvalUnit& evalUnit = processEvalUnitFile(evalUnitFile.c_str());

  printEvalUnit(evalUnit, cout);
  
  return 0;
}
