#ifndef ARABICA_XSLT_APPLY_IMPORTS_HANDLER_HPP
#define ARABICA_XSLT_APPLY_IMPORTS_HANDLER_HPP

#include "../xslt_apply_imports.hpp"

namespace Arabica
{
namespace XSLT
{

template<class stringT, class adaptorT>
class ApplyImportsHandler : public SAX::DefaultHandler<stringT, adaptorT>
{
public:
  typedef stringT string_type;
  typedef adaptorT string_adaptor;

  ApplyImportsHandler(CompilationContext<string_type, string_adaptor>& context):
    context_(context),
    applyImports_(0)
  {
  } // ApplyImportsHandler

  ~ApplyImportsHandler() 
  {
  } // ~ApplyImportsHandler

  virtual void startElement(const string_type& /* namespaceURI */,
			    const string_type& /* localName */,
			    const string_type& /* qName */,
			    const SAX::Attributes<string_type, string_adaptor>& atts)
  {
    if(applyImports_ == 0)
    {
      if(atts.getLength() != 0)
	      throw SAX::SAXException("xsl:apply-imports element does not have any attributes");
      applyImports_ = new ApplyImports<string_type, string_adaptor>();
      return;
    } // if(applyImports_ == 0)

    throw SAX::SAXException("xsl:apply-imports element must be empty");
  } // startElement

  virtual void endElement(const string_type& /* namespaceURI */,
			  const string_type& /* localName */,
			  const string_type& /* qName */)
  {
    context_.parentContainer().add_item(applyImports_);
    context_.pop();
  } // endElement

  virtual void characters(const string_type& ch)
  {
    verifyNoCharacterData<string_type, string_adaptor>(ch, StylesheetConstant<string_type, string_adaptor>::apply_imports);
  } // characters

private:
  CompilationContext<string_type, string_adaptor>& context_;
  ApplyImports<string_type, string_adaptor>* applyImports_;
}; // class ApplyImportsHandler

} // namespace XSLT
} // namespace Arabica


#endif
