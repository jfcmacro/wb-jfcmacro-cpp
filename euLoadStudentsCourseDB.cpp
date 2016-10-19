#include <locale>
#include <iostream>
#include <sstream>
#include <strstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstring>
#include <sqlite3.h>
#include <unistd.h>
#include <time.h>
#include <cstdlib>
#include <mongo/client/dbclient.h>
#include "euData.h"

using namespace std;
using namespace mongo;

struct pipe_is_space : std::ctype<char> {
  pipe_is_space() : std::ctype<char>(get_table()) { }
  static mask const* get_table() {
    static mask rc[table_size];
    rc['|'] = std::ctype_base::space;
    rc['\n'] = std::ctype_base::space;
    return &rc[0];
  }
};

static void usage(const char* prgname);

int sqlCursorSelectCourseId(void *nada, int argc, char **argv, char **colNames);
int sqlInsertTableValue(void* nada, int argc, char **argv, char **colNames);
DBClientConnection& mongoDBInit(void);
void mngDBInsert(DBClientConnection &conn, string &studentid, string &studentrepo);
int toInt(const char* str);

int
main(int argc, char *argv[]) {
  
  if (argc < 7 or argc > 11) {
    cout << "argc: " << argc << endl;
    usage(argv[0]);
  }
  
  LSCDBOptions options;
  
  int opt;

  while ((opt = getopt(argc, argv, "d:c:g:t:y:")) != -1) {
    switch (opt) {
    case 'd':
      options.dbfilename = optarg;
      break;

    case 'c':
      options.courseid = optarg;
      break;

    case 'g':
      options.groupid = optarg;
      break;

    case 'y': {
      string strYear(optarg);
      istringstream is(strYear);
      // options.year = stoi(strYear);
      is >> options.year;
      break;
    }
      
    case 't': {
      string strTerm(optarg);
      istringstream is(strTerm);
      // options.term = stoi(strTerm);
      is >> options.term;
      break;
    }
      
    default:
      usage(argv[0]);
      break;
    }
  }
  
  // Setting cin delimiter '|'
  cin.imbue(locale(cin.getloc(), new pipe_is_space));

  cout << "course: " << options.courseid << endl;
  cout << "group: " << options.groupid << endl;
  cout << "year: " << options.year << endl;
  cout << "term: " << options.term << endl;
  
  string studentid;
  string studentname;
  string studentemail;
  string studentrepo;

  sqlite3 *db;
  int rc;
  
  rc = sqlite3_open(options.dbfilename.c_str(), &db);

  if (rc) {
    
    std::cerr << "Database cannot be openned" << std::endl;
    return 1;
  }

  // check course
  char *sql;

  string selectCourseId("select courseid from courses where courseid = '" + options.courseid + "'");
  
  sql = new char[selectCourseId.size() + 1];

  strcpy(sql, selectCourseId.c_str());
  
  bool found = false;
  char *errmsg;
  
  rc = sqlite3_exec(db, sql, sqlCursorSelectCourseId, static_cast<void*>(&found), &errmsg);

  if (rc != SQLITE_OK) {
    cerr << "Error: " << errmsg << endl;
    sqlite3_free(errmsg);
    sqlite3_close(db);
    exit(1);
  }
  else if (!found) {
    cerr << "Group id: " << options.courseid << " doesn't found" << endl;
    sqlite3_close(db);
    exit(1);
  }

  delete[] sql;

  
  try {

    DBClientConnection &conn = mongoDBInit();
    cout << "Connected to mongodb OK" << endl;
  
    while (cin >> studentid >> studentname >> studentemail >> studentrepo) {
      cout << "id: " << studentid
           << " name: " << studentname
           << " email: " << studentemail
           << " repo: " << studentrepo
           << std::endl;
      
      string insertchar("insert or replace into students values ('" +
                        studentid + "', " +
                        "' '" + ", '" +
                        studentname  + "', '" +
                        studentemail + "');");
      sql = new char[insertchar.size() + 1];
      strcpy(sql, insertchar.c_str());
      
      rc = sqlite3_exec(db, sql, sqlInsertTableValue, NULL, &errmsg);
      
      if (rc != SQLITE_OK) {
        cerr << "Error: " << errmsg
             << "insertchar: " << insertchar << endl;
        sqlite3_free(errmsg);
        // sqlite3_close(db);
        // exit(1);
      }
      else {
        mngDBInsert(conn, studentid, studentrepo);
      }
      delete[] sql;
      
    }
        
  } catch (const mongo::DBException &e) {
    cout << "caugh" << e.what() << endl;
  }

  sqlite3_close(db);

  return 0;
}
  
static void usage(const char* prgname) {
  cerr << "Usage: " << prgname << " options " << endl;
  cerr << setw(20) << right << "-d <databasefile>" << endl;
  cerr << setw(20) << right << "-c <courseid>" << endl;
  cerr << setw(20) << right << "-g <groupid>" << endl;
  cerr << setw(20) << right << "[-y <year>]" << endl;
  cerr << setw(20) << right << "[-t <term>]" << endl;
  _exit(1);
}
  
int
sqlCursorSelectCourseId(void *parameter, int argc, char **argv, char **colNames) {
  bool *pBool = static_cast<bool*>(parameter);

  *pBool = argc != 0;

  return 0;
}

int
sqlInsertTableValue(void *parameter, int argc, char **argv, char **colNames) {

  return 0;
}

DBClientConnection& 
mongoDBInit(void) {
  client::initialize();
  DBClientConnection *conn;
  conn = new DBClientConnection();
  conn->connect("localhost");
  return *conn;
}


void
mngDBInsert(DBClientConnection &conn,
            string &studentid,
            string &studentrepo) {
  BSONObjBuilder obj;

  obj.append("StudentId", studentid);
  obj.append("Repo", studentrepo);
 
  conn.insert("following.StdRepos", obj.obj());
}

int
toInt(const char *str) {

  sstrstring sss(str);
  int ret;
  sss >> ret;

  return ret;
}
