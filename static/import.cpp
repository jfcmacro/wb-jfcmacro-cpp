#include "passwd.h"
#include <string.h>

extern "C" char *strdup(const char *str);

void
Passwd::_dispose() {
  if (state == defined) {
    delete pw_name; pw_name = 0;
    delete pw_passwd; pw_passwd = 0;
    delete pw_gecos; pw_gecos = 0;
    delete pw_dir; pw_dir = 0;
    delete pw_shell; pw_shell = 0;
  }
  state = undefined;
}

void
Passwd::_import(passwd *pw) {

  if (state == defined)
    _dispose();

  pw_name = strdup(pw->pw_name);
  pw_passwd = strdup(pw->pw_passwd);
  pw_uid = pw->pw_uid;
  pw_gid = pw->pw_gid;
  pw_gecos = strdup(pw->pw_gecos);
  pw_dir = strdup(pw->pw_dir);
  pw_shell = strdup(pw->pw_shell);

  state = defined;
}
