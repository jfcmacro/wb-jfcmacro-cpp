#include <iostream>
#include <fstream>
#include <yaml-cpp03/yaml.h>
#include <yaml-cpp03/eventhandler.h>
#include <yaml-cpp03/mark.h>
#include <yaml-cpp03/anchor.h>
#include <unistd.h>

using namespace std;

class EvalUnitEventHandler : public YAML::EventHandler {
public:
  EvalUnitEventHandler() {
  }
			   
  ~EvalUnitEventHandler() {
  }
  
  void OnDocumentStart(const YAML::Mark& mark) {
    cout << "This documents start on: " << mark.pos
	 << " line: " << mark.line
	 << " col: " << mark.column
	 << endl;
  }
  
  void OnDocumentEnd() {
    cout << "This documents ends" << endl;
  }
  
  void OnNull(const YAML::Mark& mark, YAML::anchor_t anchor) {
    cout << "Null where" << mark.pos
	 << " line: " << mark.line
	 << " col: " << mark.column
	 << endl;
  }
  
  void OnAlias(const YAML::Mark& mark, YAML::anchor_t anchor) {
    cout << "On alias2" << mark.pos
	 << " line: " <<  mark.line
	 << " col: " <<  mark.column
	 << endl;
  }
  
  void OnScalar(const YAML::Mark& mark, const string& tag, YAML::anchor_t anchor, const string& value) {
    cout << "scalar: " << mark.pos
    	 << " line: " << mark.line
    	 << " col: " << mark.column
    	 << " tag: " << tag
    	 << " value: " << value
    	 << endl;
  }
  void OnSequenceStart(const YAML::Mark& mark, const string& tag, YAML::anchor_t anchor) {
    cout << "Sequence start: " << mark.pos
	 << " line: " << mark.line
	 << " col: " << mark.column
	 << " tag: " << tag
	 << endl;
  }
  
  void OnSequenceEnd() {
    cout << "Sequence ends: " << endl;
  }
  
  void OnMapStart(const YAML::Mark& mark, const string& tag, YAML::anchor_t anchor) {
    cout << "Map start: " << mark.pos
	 << " line: " << mark.line
	 << " col: " << mark.column
	 << " tag: " << tag
	 << endl;
  }
  
  void OnMapEnd() {
    cout << "MapEnd" << endl;
  }
private:
};

static void usage(const char* progname) {
  cerr << "Usage: " << progname << " <yamlfile>" << endl;
  ::_exit(1);
}

int
main(int argc, char *argv[]) {

  if (argc != 2) {
    usage(argv[0]);
  }

  ifstream infile(argv[1]);

  if (!infile) {
    
    cerr << "Error yaml file: " << argv[1] << " cannot be opened" << endl;
    _exit(1);
  } 

  YAML::Parser parse(infile);
  EvalUnitEventHandler evalUnitEventHandler;
  
  if (parse.HandleNextDocument(evalUnitEventHandler)) {
    cout << "It works" << endl;
  }
  else {
    cout << "It doesn't work" << endl;
  }

  return 0;
}
