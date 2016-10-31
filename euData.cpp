#include "euData.h"

LSCDBOptions::LSCDBOptions() :
  dbfilename(getDBFilename()),
  courseid(getCourseId()),
  groupid(getGroupId()),
  year(getYear()),
  term(getTerm()) { }
  
string LSCDBOptions::getDBFilename() {
  return getStrName("DBNAME");
}
  
string LSCDBOptions::getCourseId(){
  return getStrName("COURSE");
}

string LSCDBOptions::getGroupId() {
  return getStrName("GROUP");
}
  
string LSCDBOptions::getStrName(const char* name) {
  string strRetValue("");
  char *pEnv = getenv(name);
  
  if (pEnv != NULL) {
    strRetValue = pEnv;
  }
  
  return strRetValue;
}

int LSCDBOptions::getYear() {
  return getIntValue("YEAR", true);
}

int LSCDBOptions::getTerm() {
  return getIntValue("DB_TERM", false);
}

int LSCDBOptions::getIntValue(const char *envName, bool bYear) {
  char *pEnvName = getenv(envName);
  int retValue;
  
  if (!pEnvName) {
    
    time_t dt;
    time(&dt);
    struct tm *tmm = gmtime(&dt);
    retValue = bYear ? tmm->tm_year + 1900 :
      tmm->tm_mon >= 0 and tmm->tm_mon <= 5 ? 1 : 2 ;
  }
  else {
    
    string strValue(pEnvName);
      retValue = stoi(strValue);
  }
  
  return retValue;
}
