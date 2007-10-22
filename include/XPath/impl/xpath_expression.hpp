#ifndef ARABICA_XPATHIC_XPATH_EXPRESSION_H
#define ARABICA_XPATHIC_XPATH_EXPRESSION_H

#include <string>
#include <DOM/Node.hpp>
#include "xpath_object.hpp"
#include "xpath_execution_context.hpp"

namespace Arabica
{
namespace XPath
{

template<class string_type, class string_adaptor>
class XPathExpression
{
protected:
  XPathExpression() { }

public:
  virtual ~XPathExpression() { }

  XPathValue<string_type, string_adaptor> evaluate(const DOM::Node<string_type, string_adaptor>& context) const
  {
    ExecutionContext<string_type, string_adaptor> executionContext;
    return evaluate(context, executionContext);
  } // evaluate

  virtual bool evaluateAsBool(const DOM::Node<string_type, string_adaptor>& context) const { return evaluate(context).asBool(); }
  virtual double evaluateAsNumber(const DOM::Node<string_type, string_adaptor>& context) const { return evaluate(context).asNumber(); }
  virtual string_type evaluateAsString(const DOM::Node<string_type, string_adaptor>& context) const { return evaluate(context).asString(); }
  virtual NodeSet<string_type, string_adaptor> evaluateAsNodeSet(const DOM::Node<string_type, string_adaptor>& context) const { return evaluate(context).asNodeSet(); }

  virtual XPathValue<string_type, string_adaptor> evaluate(const DOM::Node<string_type, string_adaptor>& context, 
                                              const ExecutionContext<string_type, string_adaptor>& executionContext) const = 0;

  virtual bool evaluateAsBool(const DOM::Node<string_type, string_adaptor>& context, 
															const ExecutionContext<string_type, string_adaptor>& executionContext) const { return evaluate(context, executionContext).asBool(); }
  virtual double evaluateAsNumber(const DOM::Node<string_type, string_adaptor>& context, 
                                  const ExecutionContext<string_type, string_adaptor>& executionContext) const { return evaluate(context, executionContext).asNumber(); }
  virtual string_type evaluateAsString(const DOM::Node<string_type, string_adaptor>& context, 
                                       const ExecutionContext<string_type, string_adaptor>& executionContext) const { return evaluate(context, executionContext).asString(); }
  virtual NodeSet<string_type, string_adaptor> evaluateAsNodeSet(const DOM::Node<string_type, string_adaptor>& context, 
                                                 const ExecutionContext<string_type, string_adaptor>& executionContext) const { return evaluate(context, executionContext).asNodeSet(); }


private:
  XPathExpression(const XPathExpression&);
  bool operator==(const XPathExpression&);
  XPathExpression& operator=(const XPathExpression&);
}; // class XPathExpression

template<class string_type, class string_adaptor = Arabica::default_string_adaptor<string_type> >
class XPathExpressionPtr : public boost::shared_ptr<XPathExpression<string_type, string_adaptor> > 
{ 
public:
  XPathExpressionPtr() : 
    boost::shared_ptr<XPathExpression<string_type, string_adaptor> >() { }
  explicit XPathExpressionPtr(XPathExpression<string_type, string_adaptor>* xp) : 
    boost::shared_ptr<XPathExpression<string_type, string_adaptor> >(xp) { }
  XPathExpressionPtr(const XPathExpressionPtr& rhs) : 
    boost::shared_ptr<XPathExpression<string_type, string_adaptor> >(rhs) { }
  XPathExpressionPtr& operator=(const XPathExpressionPtr& rhs)
  {
    boost::shared_ptr<XPathExpression<string_type, string_adaptor> >::operator=(rhs);
    return *this;
  } // operator=
}; // class XPathExpressionPtr

namespace impl
{
template<class string_type, class string_adaptor>
class UnaryExpression
{
public:
  UnaryExpression(XPathExpression<string_type, string_adaptor>* expr) :
      expr_(expr) { }

protected:
  ~UnaryExpression() 
  {
    delete expr_;
  } // ~UnaryExpression

  XPathExpression<string_type, string_adaptor>* expr() const { return expr_; }

private:
  XPathExpression<string_type, string_adaptor>* expr_;
}; // class UnaryExpression

template<class string_type, class string_adaptor>
class BinaryExpression
{
public:
  BinaryExpression(XPathExpression<string_type, string_adaptor>* lhs, 
                   XPathExpression<string_type, string_adaptor>* rhs) :
      lhs_(lhs), 
      rhs_(rhs) 
  { 
  } // BinaryExpression

protected:
  ~BinaryExpression() 
  { 
    delete lhs_;
    delete rhs_;
  } // ~BinaryExpression

  XPathExpression<string_type, string_adaptor>* lhs() const { return lhs_; }
  XPathExpression<string_type, string_adaptor>* rhs() const { return rhs_; }

private:
  XPathExpression<string_type, string_adaptor>* lhs_;
  XPathExpression<string_type, string_adaptor>* rhs_;
}; // class BinaryExpression

} // namespace impl
} // namespace XPath
} // namespace Arabica

#endif
