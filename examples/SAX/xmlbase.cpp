//////////////////////////////////////////////////
//
// An example application which tracks xml:base declarations,
// and prints out resolved xlink:hrefs, like those in the 
// XML Base spec example
//   http://www.w3.org/TR/xmlbase/
// $Id$
//
//////////////////////////////////////////////////

#ifdef _MSC_VER
#pragma warning(disable : 4786)
#endif

#include <SAX/helpers/DefaultHandler.hpp>
#include <SAX/InputSource.hpp>
#include <SAX/XMLReader.hpp>
#include <SAX/helpers/XMLBaseSupport.hpp>
#include <iostream>

class hrefPrinter : public SAX::DefaultHandler
{
  public:
    virtual void startElement(const std::string& namespaceURI, const std::string& localName,
                              const std::string& qName, const SAX::Attributes& atts);
    virtual void endElement(const std::string& namespaceURI, const std::string& localName,
                            const std::string& qName);

    virtual void warning(const SAX::SAXParseException& e) { fatalError(e); }
    virtual void error(const SAX::SAXParseException& e) { fatalError(e); }

  private:
    SAX::XMLBaseSupport xmlbaseTracker_;
}; // class SimpleHandler

int main(int argc, char* argv[])
{
  if(argc == 1) 
  {
    std::cout << "Usage : " << argv[0] << " xmlfile ... " << std::endl;
    return 0;
  } // if(argc == 0)

  hrefPrinter handler;

  for(int i = 1; i < argc; ++i)
  {
    try
    {
      SAX::XMLReader<std::string> myParser;
      myParser.setContentHandler(handler);
      myParser.setErrorHandler(handler);

      SAX::InputSource is(argv[i]);
      myParser.parse(is);
    } // try
    catch(std::runtime_error& e)
    {
      std::cerr << "Parse problem " << e.what() << std::endl;
    } // catch  
  } // for ...

  return 0;
} // main


void hrefPrinter::startElement(const std::string&, const std::string& localName,
                               const std::string&, const SAX::Attributes& atts)
{
  xmlbaseTracker_.startElement(atts);

  std::string href = atts.getValue("http://www.w3.org/1999/xlink", "href");
  if(href.empty())
    return;

  std::cout << "href '" << href << "' resolves to the URI '" << xmlbaseTracker_.makeAbsolute(href) << "'" << std::endl;
} // startElement

void hrefPrinter::endElement(const std::string&, const std::string& localName,
                             const std::string&)
{
  xmlbaseTracker_.endElement();
} // endElement

// end of file
