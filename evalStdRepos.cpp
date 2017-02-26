/*
 * fichero: evalStdRepos.cpp
 *
 * created: 2016-05-10
 *
 * programmer: Juan Francisco Cardona McCormick
 *
 * History of modifications:
 * 2016-11-08 - Enable to change directory of test. Change some break for continue [bug]
 * 2016-06-01 - Start of modifications.
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <stdlib.h>
#include <unistd.h>
#include "stdreposutils.h"
#include "stdinfo.h"
#include "process.h"

using namespace std;

static void usage(const char* progname) {
  cerr << "Usage: " << progname << endl
       << "[--workdir[=]arg]" << endl
       << "[--reposdir[=]arg]" << endl
       << "[--username[=]arg]" << endl
       << "[--evalunitfile[=]args]" << endl
       << "[--stdlst[=]stdcode[,stdcode]..." << endl
       << "[--resumen] <stdinfofile>" << endl;
  ::_exit(1);
}

void evalStdRepo(const string& stdId, const Estudiante& stdInfo,
                 const Options2& options, EvalUnit& evalUnit);

// int launchProcess(const string& cmd,
//                   vector<string> args,
//                   const string& msgError);

// int launchProcessInFile(const string& inFile,
//                         const string& cmd, vector<string> args,
//                         const string& msgError);

// int launchTwoProcess(const string& inFile,
//                      const string& cmd1, vector<string> args1,
//                      const string& cmd2, vector<string> args2,
//                      const string& msgError);

// int launchTwoProcessInFile(const string& inFile,
//                            const string& cmd1, vector<string> args1,
//                            const string& cmd2, vector<string> args2,
//                            const string& msgError);
int
main(int argc, char **argv) {

  int iniFich;
  Options2 options;

  iniFich = parseOptions2(options, argc, argv);

  if (iniFich == argc) {

    usage(argv[0]);
  }

  if (options.evalUnitFile.empty()) {

    cerr << "EvalUnitFile is empty" << endl;
    _exit(1);
  }

  EvalUnit& evalUnit = processEvalUnitFile(options.evalUnitFile.c_str());

  if (options.resumen) {
    cout << "--workdir: " << options.workdir << endl
         << "--reposdir: " << options.reposdir << endl
         << "--stdlst: ";

    for (vector<string>::iterator it = options.stdlst.begin();
         it != options.stdlst.end();
         ++it) {

      cout << *it;

      if ((it + 1) != options.stdlst.end())
        cout << ',';
    }

    cout  << endl
          << "--username: " << options.username << endl
          << "filename: " << argv[optind] << endl;
  }

  map <string,Estudiante> codEst;

  if (!obtenerEstudiantes(codEst, argv[optind])) {
    cerr << "student file input" << argv[optind] << endl;
    return 1;
  }

  cout << "Student loaded: " << codEst.size() << endl;

  if (chdir(options.workdir.c_str()) == 0) {
    struct stat buffer;

    if (stat(options.reposdir.c_str(),&buffer) != 0) {

      cerr << "reposdir: "
           << options.reposdir
           << " doesn't exist because errno: "
           << errno << endl;
      exit(1);
    }

    if (chdir(options.reposdir.c_str()) == 0) {

      if (options.stdlst.empty()) {

        for (map<string,Estudiante>::iterator it = codEst.begin();
             it != codEst.end();
             ++it) {

          evalStdRepo(it->first, it->second, options, evalUnit);

          chdir(options.workdir.c_str());
          chdir(options.reposdir.c_str());
        }
      }
      else {

        for (vector<string>::iterator it = options.stdlst.begin();
             it != options.stdlst.end();
             ++it) {

          cout << "Searching for: " << *it << endl;
          map<string,Estudiante>::iterator it2 = codEst.find(*it);

          if (it2 != codEst.end()) {

            evalStdRepo(it2->first, it2->second, options, evalUnit);
            chdir(options.workdir.c_str());
            chdir(options.reposdir.c_str());
          }
          else {
            cerr << "student id " << *it
                 << " doesn't exist"
                 << endl;
          }
        }
      }
    }
  }
  else {

    cerr << "workdir: " << options.workdir << " doesn't exist "
         << " errno: " << errno << endl;
    exit(1);
  }

  return 0;
}

// char* createCopyChar(const string& arg) {
//   char *ret = new char[arg.size() + 1];
//   ::strcpy(ret, arg.c_str());
//   return ret;
// }

// int launchProcess(const string& cmd,
//                   vector<string> args,
//                   const string& msgError) {

//   if (fork() == 0) {

//     char **cmdArgs = new char*[args.size()+2];

//     cmdArgs[0] = createCopyChar(cmd);

//     unsigned int i = 1;
//     for (unsigned int j = 0; j < args.size(); ++i,++j) {
      
//       cmdArgs[i] = createCopyChar(args[j]);
//     }
    
//     cmdArgs[i] = NULL;

//     execvp(cmdArgs[0], cmdArgs);

//     cerr << "This cannot happen here because: " << errno
//          << " " << strerror(errno) << endl;
    
//     exit(20);
//   }

//   int status;
//   wait(&status);

//   if (WIFEXITED(status)) {
//     if (WEXITSTATUS(status) != 0) {
//       cerr << msgError
//            << " status: " << WEXITSTATUS(status)
//            << endl;
//       return WEXITSTATUS(status);
//     }
//     return 0;
//   }
//   return -1;
// }

// int launchProcessInFile(const string& inFile,
//                         const string& cmd, vector<string> args,
//                         const string& msgError) {

//   cout << "cmd: " << cmd << " ";

//   for (unsigned int i = 0; i < args.size(); ++i) {
//     cout << args[i];
//     if (i + 1 == args.size())  cout << " ";
//   }

//   cout << endl;

//   pid_t pidChild;

//   if ((pidChild = fork()) == 0) { /* First Child */

//     char **cmdArgs = new char*[args.size()+2];

//     cmdArgs[0] = createCopyChar(cmd);

//     unsigned int i = 1;
//     for (unsigned int j = 0; j < args.size(); ++i,++j) {

//       cmdArgs[i] = createCopyChar(args[j]);
//     }

//     cmdArgs[i] = NULL;

//     int fd;

//     if ((fd = open(inFile.c_str(), O_RDONLY)) == -1) {
//       cerr << "File: " << inFile << " cannot be opened "
//            << " because " << errno << endl;
//       exit(21);
//     }

//     ::dup2(fd, STDIN_FILENO);
//     // ::dup2(pipefds[1], STDOUT_FILENO);

//     ::close(fd);
//     // ::close(pipefds[0]);
//     // ::close(pipefds[1]);

//     ::execv(cmdArgs[0], cmdArgs);

//     cerr << "This cannot happen here because: " << errno
//          << " " << strerror(errno) << endl;
//     exit(30);
//   }

//   int statChild;
//   waitpid(pidChild, &statChild, 0);

//   cout << "child end status: " << statChild <<  endl;

//   if (WIFEXITED(statChild)) {
//     if (WEXITSTATUS(statChild) != 0) {
//       cerr << msgError
//            << " status child: " << WEXITSTATUS(statChild)
//         ;
//     }
//   }

//   return -1;
// }


// int launchTwoProcessInFile(const string& inFile,
//                            const string& cmd1, vector<string> args1,
//                            const string& cmd2, vector<string> args2,
//                            const string& msgError) {

//   cout << "cmd1: " << cmd1 << " ";
//   for (unsigned int i = 0; i < args1.size(); ++i) {
//     cout << args1[i];
//     if (i + 1 == args1.size())  cout << " ";
//   }
//   cout << endl;

//   cout << "cmd2: " << cmd2 << " ";
//   for (unsigned int i = 0; i < args2.size(); ++i) {
//     cout << args2[i];
//     if (i + 1 != args2.size())  cout << " ";
//   }
//   cout << endl;

//   int pipefds[2];

//   ::pipe(pipefds);

//   pid_t pidChild1;

//   if ((pidChild1 = fork()) == 0) { /* First Child */

//     char **cmdArgs = new char*[args1.size()+2];

//     cmdArgs[0] = createCopyChar(cmd1);

//     unsigned int i = 1;
//     for (unsigned int j = 0; j < args1.size(); ++i,++j) {

//       cmdArgs[i] = createCopyChar(args1[j]);
//     }

//     cmdArgs[i] = NULL;

//     int fd;

//     if ((fd = open(inFile.c_str(), O_RDONLY)) == -1) {
//       cerr << "File: " << inFile << " cannot be opened "
//            << " because " << errno << endl;
//       exit(21);
//     }

//     ::dup2(fd, STDIN_FILENO);
//     ::dup2(pipefds[1], STDOUT_FILENO);

//     ::close(fd);
//     ::close(pipefds[0]);
//     ::close(pipefds[1]);

//     ::execv(cmdArgs[0], cmdArgs);

//     cerr << "This cannot happen here because: " << errno
//          << " " << strerror(errno) << endl;
//     exit(30);
//   }

//   pid_t pidChild2;

//   if ((pidChild2 = fork()) == 0) { /* Child 2*/
//     char **cmdArgs = new char*[args2.size()+2];

//     cmdArgs[0] = createCopyChar(cmd2);

//     unsigned int i = 1;
//     for (unsigned int j = 0; j < args2.size(); ++i,++j) {

//       cmdArgs[i] = createCopyChar(args2[j]);
//     }
//     cmdArgs[i] = NULL;

//     ::dup2(pipefds[0], STDIN_FILENO);

//     ::close(pipefds[0]);
//     ::close(pipefds[1]);

//     execvp(cmdArgs[0], cmdArgs);

//     cerr << "This cannot happen here because: " << errno
//          << " " << strerror(errno) << endl;
//     exit(40);
//   }

//   ::close(pipefds[0]);
//   ::close(pipefds[1]);

//   int statChild1;
//   waitpid(pidChild1, &statChild1, 0);

//   cout << "child1 end status: " << statChild1 <<  endl;

//   if (WIFEXITED(statChild1)) {
//     if (WEXITSTATUS(statChild1) != 0) {
//       cerr << msgError
//            << " status child 1: " << WEXITSTATUS(statChild1)
//            << endl;
//     }
//   }

//   int statChild2;

//   waitpid(pidChild2, &statChild2, 0);

//   cout << "child2 end status: " << statChild2 << endl;

//   if (WIFEXITED(statChild2)) {
//     if (WEXITSTATUS(statChild2) != 0) {
//       cerr << msgError
//            << " status child 2: " << WEXITSTATUS(statChild2)
//            << endl;
//       return WEXITSTATUS(statChild2);
//     }
//     return WEXITSTATUS(statChild2);
//   }
//   return -1;
// }

// int launchTwoProcess(const string& cmd1, vector<string> args1,
//                      const string& cmd2, vector<string> args2,
//                      const string& msgError) {

//   cout << "cmd1: " << cmd1 << " ";
//   for (unsigned int i = 0; i < args1.size(); ++i) {
//     cout << args1[i];
//     if (i + 1 == args1.size())  cout << " ";
//   }
//   cout << endl;

//   cout << "cmd2: " << cmd2 << " ";
//   for (unsigned int i = 0; i < args2.size(); ++i) {
//     cout << args2[i];
//     if (i + 1 != args2.size())  cout << " ";
//   }
//   cout << endl;

//   int pipefds[2];

//   ::pipe(pipefds);

//   pid_t pidChild1;

//   if ((pidChild1 = fork()) == 0) { /* First Child */

//     char **cmdArgs = new char*[args1.size()+2];

//     cmdArgs[0] = createCopyChar(cmd1);

//     unsigned int i = 1;
//     for (unsigned int j = 0; j < args1.size(); ++i,++j) {

//       cmdArgs[i] = createCopyChar(args1[j]);
//     }

//     cmdArgs[i] = NULL;

//     // int fd;

//     // if ((fd = open(inFile.c_str(), O_RDONLY)) == -1) {
//     //   cerr << "File: " << inFile << " cannot be opened "
//     //        << " because " << errno << endl;
//     //   exit(21);
//     // }

//     // ::dup2(fd, STDIN_FILENO);
//     ::dup2(pipefds[1], STDOUT_FILENO);

//     // ::close(fd);
//     ::close(pipefds[0]);
//     ::close(pipefds[1]);

//     ::execv(cmdArgs[0], cmdArgs);

//     cerr << "This cannot happen here because: " << errno
//          << " " << strerror(errno) << endl;
//     exit(30);
//   }

//   pid_t pidChild2;

//   if ((pidChild2 = fork()) == 0) { /* Child 2*/
//     char **cmdArgs = new char*[args2.size()+2];

//     cmdArgs[0] = createCopyChar(cmd2);

//     unsigned int i = 1;
//     for (unsigned int j = 0; j < args2.size(); ++i,++j) {

//       cmdArgs[i] = createCopyChar(args2[j]);
//     }
//     cmdArgs[i] = NULL;

//     ::dup2(pipefds[0], STDIN_FILENO);

//     ::close(pipefds[0]);
//     ::close(pipefds[1]);

//     execvp(cmdArgs[0], cmdArgs);

//     cerr << "This cannot happen here because: " << errno
//          << " " << strerror(errno) << endl;
//     exit(40);
//   }

//   ::close(pipefds[0]);
//   ::close(pipefds[1]);

//   int statChild1;
//   waitpid(pidChild1, &statChild1, 0);

//   cout << "child1 end status: " << statChild1 <<  endl;

//   if (WIFEXITED(statChild1)) {
//     if (WEXITSTATUS(statChild1) != 0) {
//       cerr << msgError
//            << " status child 1: " << WEXITSTATUS(statChild1)
//            << endl;
//     }
//   }

//   int statChild2;

//   waitpid(pidChild2, &statChild2, 0);

//   cout << "child2 end status: " << statChild2 << endl;

//   if (WIFEXITED(statChild2)) {
//     if (WEXITSTATUS(statChild2) != 0) {
//       cerr << msgError
//            << " status child 2: " << WEXITSTATUS(statChild2)
//            << endl;
//       return WEXITSTATUS(statChild2);
//     }
//     return WEXITSTATUS(statChild2);
//   }
//   return -1;
// }

bool existsFile(const string& file) {
  struct stat statBuffer;

  if (stat(file.c_str(), &statBuffer) != 0) {
    return false;
  }

  return S_ISREG(statBuffer.st_mode);
}

bool existsLocalFile(const string &file) {
  string localfile("./");

  localfile += file;

  return existsFile(localfile);
}

bool existsDir(const string& dir) {
  struct stat statBuffer;

  if (stat(dir.c_str(), &statBuffer) != 0) {
    return false;
  }

  return S_ISDIR(statBuffer.st_mode);
}

bool existsLocalDir(const string& dir) {
  string localdir("./");

  localdir += dir;

  return existsDir(localdir);
}

int chDirStr(const string& dir) {

  return chdir(dir.c_str());
}

int chLocalDirStr(const string& dir) {

  string localdir("./");

  localdir += dir;

  return chDirStr(localdir);
}

string& getCurrentDirName() {
  const size_t DIRNAMESIZE = 1024;
  char *currentDirName = new char[DIRNAMESIZE];

  getcwd(currentDirName, DIRNAMESIZE);

  string* strCurrentDirName = new string(currentDirName);
  delete []currentDirName;
  return *strCurrentDirName;
}


void evalStdRepo(const string& stdId, const Estudiante& stdInfo,
                 const Options2& options, EvalUnit& evalUnit) {

  if (!existsLocalDir(stdInfo.obtenerEmail())) {

    cerr << "Student: " << stdInfo.obtenerNombre() << endl
         << " current directory: " << ::getCurrentDirName()
         << " directory doesn't exist: " << stdInfo.obtenerEmail() << endl;
    return;
  }

  chdir(stdInfo.obtenerEmail().c_str());

  if (!existsLocalDir(evalUnit.evalUnit)) {
    cerr << "Student: " << stdInfo.obtenerNombre() << endl
         << " directory doesn't exist: " << evalUnit.evalUnit << endl;
    return;
  }

  chLocalDirStr(evalUnit.evalUnit);

  if (!existsLocalDir(evalUnit.name)) {
    cerr << "Student: " << stdInfo.obtenerNombre() << endl
         << " directory doesn't exist: " << evalUnit.evalUnit << endl;
    return;
  }

  chLocalDirStr(evalUnit.name);

  cout << "Student: " << stdInfo.obtenerNombre() << endl
       << "Current directory: " << ::getCurrentDirName() << endl;

  float totalStudent = 0.0f;

  for (unsigned int i = 0; i < evalUnit.elemsToEval.size(); ++i) {

    cout << "Element to eval name: " << evalUnit.elemsToEval[i].name << endl;

    // Moving to directory where elements are
    if (chLocalDirStr(evalUnit.elemsToEval[i].name.c_str()) != 0) {

      cerr << "Student: " << stdInfo.obtenerNombre() << endl
           << " evaluating..." << endl
          << " directory doesn't exist: "
          << evalUnit.elemsToEval[i].name.c_str() << endl
          << " current directory: " << ::getCurrentDirName()
          << endl;

      continue;
    }

    char pwd[256];
    ::getcwd(pwd,256);
    
    cout << "Now at: " <<  pwd << endl;

    vector<string> args;

    if (!evalUnit.elemsToEval[i].compileCmd.empty()) {
      cout << "Preparing cleaning compiling " << endl;

      if (evalUnit.elemsToEval[i].compileCmd == "make" or
          evalUnit.elemsToEval[i].compileCmd == "mvn") {

        args.push_back("clean");
        string msg("compiling was not possible");

        if (launchProcess(evalUnit.elemsToEval[i].compileCmd, args, msg) != 0) {

          cerr << "Process cannot be cleaned" << endl;
          string up("..");
          chDirStr(up);
          continue;
        }
      }

      // make all
      // cout << "Preparing compiling " << endl;

      args.clear();
      // args.push_back("all");
      string msg("Preparing to compile with make all");

      if (evalUnit.elemsToEval[i].compileCmd == "make") {
        // args.push_back("");
      }
      else if (evalUnit.elemsToEval[i].compileCmd == "mvn") {
        args.push_back("compile");
      }

      if (launchProcess(evalUnit.elemsToEval[i].compileCmd, args, msg) != 0) {

        string cmdVi("vim");
        vector<string> argsVi;
        // argsVi.push_back(evalUnit.elemsToEval[i].srcfile);

        for (unsigned int nsrcf = 0;
             nsrcf < evalUnit.elemsToEval[i].srcfile.size();
             ++nsrcf) {
          argsVi.push_back(evalUnit.elemsToEval[i].srcfile[nsrcf]);

          cout << "Estudiante: " << stdInfo.obtenerNombre()
               << " fichero: " << evalUnit.elemsToEval[i].srcfile[nsrcf] << endl
               << "<presione cualquier tecla>" << endl;
          cin.get();
          string msgVi("Msg vi");

          launchProcess(cmdVi, argsVi, msgVi);
          argsVi.clear();
          cout << "Ready for the next file" << endl;
        }

        string up("..");
        chDirStr(up);
        continue;
      }
    }

    // Compute units
    float unitElemToEval =
      evalUnit.elemsToEval[i].value / evalUnit.elemsToEval[i].tests.size();
    float totalElemToEval = 0.0f;

    // preparing for copy test files
    bool anyTestFailed = false;
    string dirTest(evalUnit.workdir);
    dirTest += "/" + evalUnit.elemsToEval[i].name + "/";

    for (unsigned int k = 0; k < evalUnit.elemsToEval[i].tests.size(); ++k) {

      string inFile = evalUnit.elemsToEval[i].tests[k].inFile;
      string outFile = evalUnit.elemsToEval[i].tests[k].outFile;
      string srcInFile(dirTest);
      srcInFile += inFile;
      string srcOutFile(dirTest);
      srcOutFile += outFile;

      if (!existsFile(srcInFile) || !existsFile(srcOutFile)) {
        cerr << "[EvalStdRepos] Warning srcinfile: " << srcInFile << endl
             << "or srcoutfile: " << srcOutFile << " doesn't exits" << endl;
        continue;
      }

      // copy inFile
      ifstream srcIn(srcInFile.c_str());
      ofstream dstIn(inFile.c_str());

      dstIn << srcIn.rdbuf();

      srcIn.close();
      dstIn.close();

      // copy outFile
      ifstream srcOut(srcOutFile.c_str());
      ofstream dstOut(outFile.c_str());

      dstOut << srcOut.rdbuf();

      srcOut.close();
      dstOut.close();

      args.clear();

      // no redirect one comand
      // redirect one command
      // no redirect two command
      // redirect one command

      if (evalUnit.elemsToEval[i].tests[k].redirect and
          evalUnit.elemsToEval[i].tests[k].cmdToTest2.size() == 0) {

        vector<string> args2;
        args2.push_back("-");
        args2.push_back(outFile);
        int retCmdDiff;
        string msgCmdDiff("Error message");

        if (evalUnit.elemsToEval[i].tests[k].args.size() > 0) {
          args.insert(args.end(), evalUnit.elemsToEval[i].tests[k].args.begin(),
                      evalUnit.elemsToEval[i].tests[k].args.end());
        }

        if ((retCmdDiff =
             launchTwoProcessInFile(inFile,
                                    evalUnit.elemsToEval[i].tests[k].cmdToTest,
                                    args,
                                    evalUnit.elemsToEval[i].tests[k].cmdToDiff,
                                    args2,
                                    msgCmdDiff)) != 0) {
          anyTestFailed = true;
          switch(retCmdDiff) {
          case 1:
            cout << "There are differences between output and expected ouput"
                 << endl;
            break;
          default:
            cout << "Another kind of error: " << retCmdDiff << endl;
            break;
          }
        }
        else {
          cout << "Test passed" << endl;
          totalElemToEval += unitElemToEval;
        }
      }
      else if (evalUnit.elemsToEval[i].tests[k].redirect and
               evalUnit.elemsToEval[i].tests[k].cmdToTest2.size() != 0) {

        if (evalUnit.elemsToEval[i].tests[k].args.size() > 0) {
          args.insert(args.end(), evalUnit.elemsToEval[i].tests[k].args.begin(),
                      evalUnit.elemsToEval[i].tests[k].args.end());
        }

        int retCmdDiff;
        string msgCmdDiff("Error message");

        if ((launchProcessInFile(inFile,
                                 evalUnit.elemsToEval[i].tests[k].cmdToTest,
                                 args,
                                 msgCmdDiff)) != 0) {
          cerr << "First command failed" << endl;
        }
        else {
          vector<string> args2;

          if (evalUnit.elemsToEval[i].tests[k].args2.size() > 0) {
            args2.insert(args.end(),
                         evalUnit.elemsToEval[i].tests[k].args2.begin(),
                         evalUnit.elemsToEval[i].tests[k].args2.end());
          }

          vector<string> args3;
          args3.push_back("-");
          args3.push_back(outFile);

          if ((retCmdDiff =
               launchTwoProcess(evalUnit.elemsToEval[i].tests[k].cmdToTest2,
                                args2,
                                evalUnit.elemsToEval[i].tests[k].cmdToDiff,
                                args3,
                                msgCmdDiff)) != 0) {

            anyTestFailed = true;
            switch(retCmdDiff) {
            case 1:
              cout << "There are difference between output and expected ouput"
                   << endl;
              break;
            default:
              cout << "Another kind of error: " << retCmdDiff << endl;
              break;
            }
          }
          else {
            cout << "Test passed" << endl;
            totalElemToEval += unitElemToEval;
          }
        }
      }
      else if (!evalUnit.elemsToEval[i].tests[k].redirect and
               evalUnit.elemsToEval[i].tests[k].cmdToTest2.size() == 0) {

        args.push_back(inFile);
        vector<string> args2;
        args2.push_back("-");
        args2.push_back(outFile);
        int retCmdDiff;
        string msgCmdDiff("Error message");

        if (evalUnit.elemsToEval[i].tests[k].args.size() > 0) {
          args.insert(args.end(), evalUnit.elemsToEval[i].tests[k].args.begin(),
                      evalUnit.elemsToEval[i].tests[k].args.end());
        }

        if ((retCmdDiff =
             launchTwoProcess(evalUnit.elemsToEval[i].tests[k].cmdToTest,
                              args,
                              evalUnit.elemsToEval[i].tests[k].cmdToDiff,
                              args2,
                              msgCmdDiff)) != 0) {
          anyTestFailed = true;
          switch(retCmdDiff) {
          case 1:
            cout << "There are difference between output and expected ouput"
                 << endl;
            break;
          default:
            cout << "Another kind of error: " << retCmdDiff << endl;
            break;
          }
        }
        else {
          cout << "Test passed" << endl;
          totalElemToEval += unitElemToEval;
        }
      }
      else if (!evalUnit.elemsToEval[i].tests[k].redirect and
               evalUnit.elemsToEval[i].tests[k].cmdToTest2.size() != 0) {

        if (evalUnit.elemsToEval[i].tests[k].args.size() > 0) {
          args.insert(args.end(), evalUnit.elemsToEval[i].tests[k].args.begin(),
                      evalUnit.elemsToEval[i].tests[k].args.end());
        }

        int retCmdDiff;
        string msgCmdDiff("Error message");

        if ((launchProcessInFile(inFile,
                                 evalUnit.elemsToEval[i].tests[k].cmdToTest,
                                 args,
                                 msgCmdDiff)) != 0) {
          cerr << "First command failed" << endl;
        }
        else {
          vector<string> args2;

          if (evalUnit.elemsToEval[i].tests[k].args2.size() > 0) {
            args2.insert(args.end(),
                         evalUnit.elemsToEval[i].tests[k].args2.begin(),
                         evalUnit.elemsToEval[i].tests[k].args2.end());
          }

          vector<string> args3;
          args3.push_back("-");
          args3.push_back(outFile);

          if ((retCmdDiff =
               launchTwoProcess(evalUnit.elemsToEval[i].tests[k].cmdToTest2,
                                args2,
                                evalUnit.elemsToEval[i].tests[k].cmdToDiff,
                                args3,
                                msgCmdDiff)) != 0) {

            anyTestFailed = true;
            switch(retCmdDiff) {
            case 1:
              cout << "There are difference between output and expected ouput"
                   << endl;
              break;
            default:
              cout << "Another kind of error: " << retCmdDiff << endl;
              break;
            }
          }
          else {
            cout << "Test passed" << endl;
            totalElemToEval += unitElemToEval;
          }
        }
      }
    }

    totalStudent += totalElemToEval;

    if (anyTestFailed) {

      string cmdVi("vim");
      vector<string> argsVi;
      string msgVi("Algo esta mal");

      for (unsigned int nsrcf = 0;
           nsrcf < evalUnit.elemsToEval[i].srcfile.size();
           ++nsrcf) {
        argsVi.push_back(evalUnit.elemsToEval[i].srcfile[nsrcf]);

        cout << "Estudiante: " << stdInfo.obtenerNombre()
             << " fichero: " << evalUnit.elemsToEval[i].srcfile[nsrcf] << endl
             << "<presione cualquier tecla>" << endl;
        cin.get();

        launchProcess(cmdVi, argsVi, msgVi);
        argsVi.clear();
        cout << "Ready for the next file" << endl;
      }
    }

    cout << "Element Evalued: " << totalElemToEval << endl;
    string up("..");
    chDirStr(up);
  }

  cout << "Student: " << stdInfo.obtenerNombre()
       << " grade: " << 5 * totalStudent << endl;
  cout << "<Presione cualquier tecla para continuar>";
  cout.flush();
  cin.get();

  return;
}
