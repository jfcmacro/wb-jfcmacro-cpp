#include <xercesc/sax/HandlerBase.hpp>

class MySaxHandler : public HandlerBase {
public:
  MySaxHandler();
  void startElement(const XMLCh* const, AttributeList&);
  void startDocument();
  void endElement (const XMLCh *const name);
  void fatalError(const SAXParseException&);
  void endDocument();
};
