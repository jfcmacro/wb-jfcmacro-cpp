#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>

#include <iostream>

using namespace std;
using namespace xercesc;

class MyDOMErrorHandler : public DOMErrorHandler {
public:
  MyDOMErrorHandler() : DOMErrorHandler() { }
  void warning(const SAXParseException &exc) {
  }
  void error(const SAXParserException &exc) {
  }
  void fatalError(const SAXParserException &exc) {
  }
  void resetErrors() {
  }
};

int main (int argc, char* args[]) {

  try {
    XMLPlatformUtils::Initialize();
  }
  catch (const XMLException& toCatch) {
    char* message = XMLString::transcode(toCatch.getMessage());
    cout << "Error during initialization! :\n"
	 << message << "\n";
    XMLString::release(&message);
    return 1;
  }


  XMLCh tempStr[100];
  XMLString::transcode("LS", tempStr, 99);
  DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);
  DOMLSParser* parser = ((DOMImplementationLS*)impl)->createLSParser(DOMImplementationLS::MODE_SYNCHRONOUS, 0);

  // optionally you can set some features on this builder
  if (parser->getDomConfig()->canSetParameter(XMLUni::fgDOMValidate, true))
    parser->getDomConfig()->setParameter(XMLUni::fgDOMValidate, true);
  if (parser->getDomConfig()->canSetParameter(XMLUni::fgDOMNamespaces, true))
    parser->getDomConfig()->setParameter(XMLUni::fgDOMNamespaces, true);
  if (parser->getDomConfig()->canSetParameter(XMLUni::fgDOMDatatypeNormalization, true))
    parser->getDomConfig()->setParameter(XMLUni::fgDOMDatatypeNormalization, true);


  // optionally you can implement your DOMErrorHandler (e.g. MyDOMErrorHandler)
  // and set it to the builder
  MyDOMErrorHandler* errHandler = new MyDOMErrorHandler();
  parser->getDomConfig()->setParameter(XMLUni::fgDOMErrorHandler, errHandler);

  char* xmlFile = "x1.xml";
  DOMDocument *doc = 0;

  try {
    doc = parser->parseURI(xmlFile);
  }
  catch (const XMLException& toCatch) {
    char* message = XMLString::transcode(toCatch.getMessage());
    cout << "Exception message is: \n"
	 << message << "\n";
    XMLString::release(&message);
    return -1;
  }
  catch (const DOMException& toCatch) {
    char* message = XMLString::transcode(toCatch.msg);
    cout << "Exception message is: \n"
	 << message << "\n";
    XMLString::release(&message);
    return -1;
  }
  catch (...) {
    cout << "Unexpected Exception \n" ;
    return -1;
  }

  parser->release();
  delete errHandler;
  return 0;
}
