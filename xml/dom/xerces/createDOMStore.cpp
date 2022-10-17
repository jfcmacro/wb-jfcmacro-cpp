#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/util/OutOfMemoryException.hpp>
#include <iostream>

// ---------------------------------------------------------------------------
//  This is a simple class that lets us do easy (though not terribly efficient)
//  trancoding of char* data to XMLCh data.
// ---------------------------------------------------------------------------
class XStr
{
public :
  // -----------------------------------------------------------------------
  //  Constructors and Destructor
  // -----------------------------------------------------------------------
  XStr(const char* const toTranscode)
  {
    // Call the private transcoding method
    fUnicodeForm = xercesc::XMLString::transcode(toTranscode);
  }

  ~XStr()
  {
    xercesc::XMLString::release(&fUnicodeForm);
  }


  // -----------------------------------------------------------------------
  //  Getter methods
  // -----------------------------------------------------------------------
  const XMLCh* unicodeForm() const
  {
    return fUnicodeForm;
  }

private :
  // -----------------------------------------------------------------------
  //  Private data members
  //
  //  fUnicodeForm
  //      This is the Unicode XMLCh format of the string.
  // -----------------------------------------------------------------------
  XMLCh*   fUnicodeForm;
};

#define X(str) XStr(str).unicodeForm()



int
main(int argC, char*[]) {
  // Initialize the XML4C2 system.
  try {
    xercesc::XMLPlatformUtils::Initialize();
  }
  catch(const xercesc::XMLException& toCatch)
    {
      char *pMsg = xercesc::XMLString::transcode(toCatch.getMessage());
      XERCES_STD_QUALIFIER cerr << "Error during Xerces-c Initialization.\n"
				<< "  Exception message:"
				<< pMsg;
      xercesc::XMLString::release(&pMsg);
      return 1;
    }

  // Watch for special case help request
  int errorCode = 0;
  if (argC > 1)
    {
      XERCES_STD_QUALIFIER cout << "\nUsage:\n"
	"    CreateDOMDocument\n\n"
	"This program creates a new DOM document from scratch in memory.\n"
	"It then prints the count of elements in the tree.\n"
				<< XERCES_STD_QUALIFIER endl;
      errorCode = 1;
    }
  if(errorCode) {
    xercesc::XMLPlatformUtils::Terminate();
    return errorCode;
  }

  {
    //  Nest entire test in an inner block.
    //  The tree we create below is the same that the XercesDOMParser would
    //  have created, except that no whitespace text nodes would be created.

    // <company>
    //     <product>Xerces-C</product>
    //     <category idea='great'>XML Parsing Tools</category>
    //     <developedBy>Apache Software Foundation</developedBy>
    // </company>

    xercesc::DOMImplementation  *impl =  xercesc::DOMImplementationRegistry::getDOMImplementation(X("Core"));
    xercesc::DOMLSSerializer    *serializer = ((xercesc::DOMImplementationLS*)impl)->createLSSerializer();
    xercesc::DOMLSOutput        *outputDesc = ((xercesc::DOMImplementationLS*)impl)->createLSOutput();
    xercesc::XMLFormatTarget    *formTarget = new xercesc::LocalFileFormatTarget("/tmp/course.xml");
    outputDesc->setByteStream(formTarget);

    xercesc::DOMConfiguration* serializerConfig = serializer->getDomConfig();

    if (serializerConfig->canSetParameter(xercesc::XMLUni::fgDOMXMLDeclaration, false))
      serializerConfig->setParameter(xercesc::XMLUni::fgDOMXMLDeclaration, false);

    if (impl != NULL)
      {
	try
	  {
	    xercesc::DOMDocument* doc = impl->createDocument(
							     0,                    // root element namespace URI.
							     X("course"),         // root element name
							     0);                   // document type object (DTD).
	    
	    xercesc::DOMElement* rootElem = doc->getDocumentElement();

	    rootElem->setAttribute(X("url_name"), X("S4N_Prueba_01_20211117"));
	    rootElem->setAttribute(X("org"), X("S4N"));
	    rootElem->setAttribute(X("course"), X("S4N_Prueba_01"));

	    serializer->write(doc, outputDesc);

	    doc->release();
	    outputDesc->release();
	    serializer->release();

	    delete formTarget;
	  }
	catch (const xercesc::OutOfMemoryException&)
	  {
	    XERCES_STD_QUALIFIER cerr << "OutOfMemoryException" << XERCES_STD_QUALIFIER endl;
	    errorCode = 5;
	  }
	catch (const xercesc::DOMException& e)
	  {
	    XERCES_STD_QUALIFIER cerr << "DOMException code is:  " << e.code << XERCES_STD_QUALIFIER endl;
	    errorCode = 2;
	  }
	catch (...)
	  {
	    XERCES_STD_QUALIFIER cerr << "An error occurred creating the document" << XERCES_STD_QUALIFIER endl;
	    errorCode = 3;
	  }
      }  // (inpl != NULL)
    else
      {
	XERCES_STD_QUALIFIER cerr << "Requested implementation is not supported" << XERCES_STD_QUALIFIER endl;
	errorCode = 4;
      }
  }

  xercesc::XMLPlatformUtils::Terminate();
  return errorCode;
}
