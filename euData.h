#pragma
#include <string>

using namespace std;

struct LSCDBOptions {
  string dbfilename;
  string courseid;
  string groupid;
  int year;
  int term;
  
  LSCDBOptions();

private:
  static string getDBFilename();
  
  static string getCourseId();
  
  static string getGroupId();
  
  static string getStrName(const char* name);
  
  static int getYear();
  
  static int getTerm();

  static int getIntValue(const char *envName, bool bYear);
};
