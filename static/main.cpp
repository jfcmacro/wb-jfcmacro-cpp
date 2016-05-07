#include <iostream>
#include <string.h>
#include "passwd.h"

using namespace std;

int
main(int argc, char const **argv) {
  unsigned ux;
  Passwd pw;
  const char *accts[] = { "uucp", "xyzzy", "games" };

  (void) argc;
  (void) argv;

  try {
    pw.getuid(0);
    cout << "Root's home dir is " << pw.pw_dir << endl;
  } catch (int e) {
    cerr << strerror(e) << ": looking up uid(0)" << endl;
  }

  for (ux = 0; ux < sizeof accts/sizeof accts[0]; ++ux) {
    try {
      pw.getnam(accts[ux]);
      cout << "Account " << accts[ux]
	   << " uses the shell " << pw.pw_shell << endl;
    } catch (int e) {
      cerr << strerror(e) << ": looking up account "
	   << accts[ux] << endl;
    }
  }
  return 0;
}
