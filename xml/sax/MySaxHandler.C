#include "MySaxHandler.hpp"
#include <xercesc/util/XMLString.hpp>
#include <iostream>

using namespace std;

MySaxHandler::MySaxHandler()
{
}

void MySaxHandler::startElement(const XMLCh* const name,
                           AttributeList& attributes)
{
  cout << "I saw element: "  << XMLString::transcode(name) 
       << endl;
}

void MySaxHandler::fatalError(const SAXParseException& exception)
{
  cout << "Fatal Error: " << XMLString::transcode(exception.getMessage())
       << " at line: " << exception.getLineNumber()
       << endl;
}

void MySaxHandler::startDocument()
{
  cout << "start of document" << endl;
} 

void MySaxHandler::endElement(const XMLCh *const name)
{
  cout << "end elemet" << endl;
}

void MySaxHandler::endDocument()
{
  cout << "End Document" << endl;
}
