#ifndef ARABICA_XSLT_TEMPLATE_HANDLER_HPP
#define ARABICA_XSLT_TEMPLATE_HANDLER_HPP

#include "../xslt_template.hpp"
#include "xslt_item_container_handler.hpp"

namespace Arabica
{
namespace XSLT
{

class TemplateHandler : public ItemContainerHandler<Template>
{
public:
  TemplateHandler(CompilationContext& context) :
    ItemContainerHandler<Template>(context),
    done_params_(false)
  {
  } // TemplateHandler

protected:
  virtual Template* createContainer(const std::string& namespaceURI,
                                    const std::string& localName,
                                    const std::string& qName,
                                    const SAX::Attributes<std::string>& atts)
  {
    const std::string& match = atts.getValue("match");
    if((match == "") && (atts.getValue("name") == ""))
      throw SAX::SAXException("xsl:template must have a match and/or a name attribute");

    if((atts.getValue("mode") != "") && (match == ""))
      throw SAX::SAXException("xsl:template may not have a mode without a match");

    std::pair<std::string, std::string> name;
    if(atts.getValue("name") != "")
      name = context().processQName(atts.getValue("name"));

    std::pair<std::string, std::string> mode;
    if(atts.getValue("mode") != "")
      mode = context().processQName(atts.getValue("mode"));

    if(match == "")
      return new Template(name,
                  			  mode,
			                    atts.getValue("priority"));

    return new Template(context().xpath().compile_match(match),
                  			name,
			                  mode,
			                  atts.getValue("priority"));
  } // createContainer

  virtual bool createChild(const std::string& namespaceURI,
                           const std::string& localName,
                           const std::string& qName,
                           const SAX::Attributes<std::string>& atts)
  {
    if((namespaceURI == StylesheetConstant::NamespaceURI()) &&
       (localName == "param"))
    {
      if(!done_params_)
      {
        context().push(container(),
                       new VariableHandler<Param>(context()),
                       namespaceURI, 
                       qName, 
                       localName, 
                       atts);
        return true;
      }
      else
        throw SAX::SAXException("xsl:param must immediately follow xsl:template");
    }

    done_params_ = true;
    return ItemContainerHandler<Template>::createChild(namespaceURI, localName, qName, atts);
  } // createChild

public:
  virtual void endElement(const std::string& namespaceURI,
                          const std::string& localName,
                          const std::string& qName)
  {
    context().stylesheet().add_template(container());
    context().pop();
  } // endElement

private:
  bool done_params_;
}; // class TemplateHandler

} // namespace XSLT
} // namespace Arabica
#endif // ARABICA_XSLT_TEMPLATE_HANDLER_HPP

