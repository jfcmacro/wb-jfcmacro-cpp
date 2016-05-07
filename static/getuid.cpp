#include <errno.h>
#include "passwd.h"

char*
Passwd::getuid(uid_t uid) {
  passwd *p = 0;
  if (state == defined)
    _dispose();

  e = errno = 0;
  p = ::getpwuid(uid);

  if (!p) {
    if (!errno)
      e = ENOENT;
    else
      e = errno;
    throw e;
  }

  _import(p);
  return this->pw_name;
}

int
Passwd::getnam(const char* name) {
  passwd *p = 0;

  if (state == defined)
    _dispose();

  e = errno = 0;
  p = ::getpwnam(name);

  if (!p) {
    if (!errno)
      e = ENOENT;
    else
      e = errno;
    throw e;
  }

  _import(p);
  return p->pw_uid;
}
