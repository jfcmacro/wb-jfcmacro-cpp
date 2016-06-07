#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <map>
#include <unistd.h>

using namespace std;

struct Student {
  string id;
  string name;
  string email;
};

static void usage(const char* progname) {
  cerr << "Usage: " << progname
       << " [<filename>] "
       << endl;
  _exit(1);
}

int
main(int argc, const char *argv[]) {

  istream* input;
  
  switch (argc) {
  case 1:
    input = &cin;
    break;

  case 2:
    {
      ifstream* ifs = new ifstream(argv[1]);

      if (!*ifs) {
	usage(argv[0]);
      }

      input = ifs;
    }
    break;

  default:
    usage(argv[0]);
    break;
  }

  const int MAXBUFFER = 256;
  char buffer[MAXBUFFER];
  map<string, vector<Student> > repos;
  
  while (input->getline(buffer, MAXBUFFER)) {
    string str(buffer);
    stringstream ss(buffer);
    while (ss.good()) {
      Student *std = new Student();
      string repo;
     
      getline(ss, std->id, '|');
      getline(ss, std->name, '|');
      getline(ss, std->email, '|');
      getline(ss, repo);

      if (repos.find(repo) == repos.end()) {
	vector<Student> *stds = new vector<Student>();
	stds->push_back(*std);
	repos[repo] = *stds;
      }
      else {
	repos[repo].push_back(*std);
      }
    }
  }

  ::srand(::time(0));
  
  for (map<string, vector<Student> >::iterator it = repos.begin();
       it != repos.end();
       ++it) {
    cout << "Repo: " << it->first << endl;
    cout << "Students: " << endl;
    random_shuffle(it->second.begin(), it->second.end());

    if (it->second.size() == 1) {
      cout << "First and second"
	   << " id: " << it->second[0].id
	   << " name: " << it->second[0].name
	   << " email: " << it->second[0].email
	   << endl;
    }
    else {

      cout << "First"
	   << " id: " << it->second[0].id
	   << " name: " << it->second[0].name
	   << " email: " << it->second[0].email
	   << endl;
    
      cout << "Second: " 
	   << " id: " << it->second[1].id
	   << " name: " << it->second[1].name
	   << " email: " << it->second[1].email
	   << endl;
    }

    cout << "Repos: " << repos.size() << endl;
    // for (vector<Student>::iterator that = it->second.begin();
    // 	 that != it->second.end();
    // 	 ++that) {

    //   cout << "id: " << that->id
    // 	   << " name: " << that->name
    // 	   << " email: " << that->email
    // 	   << endl;
    // }
  }

  return 0;
  // srand(time(NULL));
  // vector<string> sust1;
  // vector<string> sust2;

  // int nElem = estudiantes.size() / 2;
  
  // for (int i = 0; i < nElem; i++) {
  //   int ne = rand() % estudiantes.size();
  //   sust1.push_back(estudiantes[ne]);
  //   estudiantes.erase(estudiantes.begin() + ne);
  // }

  // for (vector<string>::iterator it = estudiantes.begin();
  //      it != estudiantes.end(); ++it) {
  //   sust2.push_back(*it);
  // }

  // // cout << "Estudiantes para la primera sustentacion"
  // //      << endl;

  // ofstream out1("/home/fcardona/tmp/st0244-2015-2-Sust-01.dat");
  
  // for (vector<string>::iterator it = sust1.begin();
  //      it != sust1.end(); ++it) {
  //   out1 << *it << endl;
  // }

  // ofstream out2("/home/fcardona/tmp/st0244-2015-2-Sust-02.dat");
 
  // for (vector<string>::iterator it = sust2.begin();
  //      it != sust2.end(); ++it) {
  //   out2 << *it << endl;
  // }
  
  return 0;
}
