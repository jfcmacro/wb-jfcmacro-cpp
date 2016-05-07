#pragma once

#include <sys/types.h>
#include <pwd.h>

class Passwd : public passwd {
  enum {
    undefined,
    defined
  } state;
  int e;
 protected:
  void _dispose();
  void _import(passwd *p);
 public:
  Passwd()
    { state = undefined;
      e = 0;
    }
  ~Passwd()
    { _dispose(); }
  inline int isValid()
  { return state == defined ? 1 : 0; }
  inline int getError()
  { return e; }
  char *getuid(uid_t uid);
  int getnam(const char *name);
};
