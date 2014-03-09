#include <iostream>
#include <stdlib.h>
#include <xercesc/util/PlatformUtils.hpp> 
#include <xercesc/util/XMLException.hpp>
#include <xercesc/parsers/SAXParser.hpp>
#include <xercesc/sax/DocumentHandler.hpp>
#include "MySaxHandler.hpp"

using namespace std;

static void usage(char* args[]) {

  cerr << args[0] << ": XMLfile" << endl;
  ::exit(1);
}

ostream& operator<<(ostream& target, const DOMString& toWrite);

int main (int argc, char* args[]) {

    try {
        XMLPlatformUtils::Initialize();
    }
    catch (const XMLException& toCatch) {
        cout << "Error during initialization! :\n"
             << DOMString(toCatch.getMessage()) << "\n";
        return 1;
    }

    if (argc != 2) {
      usage(args);
    }

    char* xmlFile = args[1];

    SAXParser* parser = new SAXParser();
    parser->setDoValidation(true);    // optional.
    parser->setDoNamespaces(true);    // optional

    DocumentHandler* docHandler = new MySaxHandler();
    ErrorHandler* errHandler = (ErrorHandler*) docHandler;
    parser->setDocumentHandler(docHandler);
    parser->setErrorHandler(errHandler);

    try {
        parser->parse(xmlFile);
    }
    catch (const XMLException& toCatch) {
        cout << "Exception message is: \n"
             << DOMString(toCatch.getMessage()) << "\n" ;
        return -1;
    }
    catch (const SAXParseException& toCatch) {
        cout << "Exception message is: \n"
             << DOMString(toCatch.getMessage()) << "\n" ;
        return -1;
    }
    catch (...) {
        cout << "Unexpected Exception \n" ;
        return -1;
    }
}

// ---------------------------------------------------------------------------
//  ostream << DOMString
//
//  Stream out a DOM string. Doing this requires that we first transcode
//  to char * form in the default code page for the system
// ---------------------------------------------------------------------------
ostream& operator<< (ostream& target, const DOMString& s)
{
    char *p = s.transcode();
    target << p;
    delete [] p;
    return target;
}
