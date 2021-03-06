#ifndef test_documenttypegetentities
#define test_documenttypegetentities


/*
This C++ source file was generated for Arabica
from the source document contained in the W3C
DOM Conformance Test Suite.
The source document contained the following notice:


Copyright (c) 2001-2004 World Wide Web Consortium,
(Massachusetts Institute of Technology, Institut National de
Recherche en Informatique et en Automatique, Keio University). All
Rights Reserved. This program is distributed under the W3C's Software
Intellectual Property License. This program is distributed in the
hope that it will be useful, but WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.
See W3C License http://www.w3.org/Consortium/Legal/ for more details.

*/
/**
 *     The "getEntities()" method is a NamedNodeMap that contains
 *    the general entities for this document. 
 *    
 *    Retrieve the Document Type for this document and create 
 *    a NamedNodeMap of all its entities.  The entire map is
 *    traversed and the names of the entities are retrieved.
 *    There should be 5 entities.  Duplicates should be ignored.
* @author NIST
* @author Mary Brady
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-1788794630">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-1788794630</a>
*/

template<class string_type, class string_adaptor>
class documenttypegetentities : public DOMTestCase<string_type, string_adaptor> 
{
    typedef DOMTestCase<string_type, string_adaptor> baseT;
   public: 
     documenttypegetentities(std::string name) : baseT(name)
     {

       //   check if loaded documents are supported for content type
       const std::string contentType = baseT::getContentType();
    baseT::preload(contentType, "staff", false);
    }

  typedef typename Arabica::DOM::DOMImplementation<string_type, string_adaptor>  DOMImplementation;
  typedef typename Arabica::DOM::Document<string_type, string_adaptor> Document; 
  typedef typename Arabica::DOM::DocumentType<string_type, string_adaptor> DocumentType;
  typedef typename Arabica::DOM::DocumentFragment<string_type, string_adaptor> DocumentFragment; 
  typedef typename Arabica::DOM::Node<string_type, string_adaptor> Node;
  typedef typename Arabica::DOM::Element<string_type, string_adaptor> Element;
  typedef typename Arabica::DOM::Attr<string_type, string_adaptor> Attr;
  typedef typename Arabica::DOM::NodeList<string_type, string_adaptor> NodeList;
  typedef typename Arabica::DOM::NamedNodeMap<string_type, string_adaptor> NamedNodeMap;
  typedef typename Arabica::DOM::Entity<string_type, string_adaptor> Entity;
  typedef typename Arabica::DOM::EntityReference<string_type, string_adaptor> EntityReference;
  typedef typename Arabica::DOM::CharacterData<string_type, string_adaptor> CharacterData;
  typedef typename Arabica::DOM::CDATASection<string_type, string_adaptor> CDATASection;
  typedef typename Arabica::DOM::Text<string_type, string_adaptor> Text;
  typedef typename Arabica::DOM::Comment<string_type, string_adaptor> Comment;
  typedef typename Arabica::DOM::ProcessingInstruction<string_type, string_adaptor> ProcessingInstruction;
  typedef typename Arabica::DOM::Notation<string_type, string_adaptor> Notation;

  typedef typename Arabica::DOM::DOMException DOMException;
  typedef string_type String;
  typedef string_adaptor SA;
  typedef bool boolean;


   /*
    * Runs the test case.
    */
   void runTest()
   {
      Document doc;
      DocumentType docType;
      NamedNodeMap entityList;
      String name;
      std::vector<string_type> expectedResult;
      expectedResult.push_back(SA::construct_from_utf8("ent1"));
      expectedResult.push_back(SA::construct_from_utf8("ent2"));
      expectedResult.push_back(SA::construct_from_utf8("ent3"));
      expectedResult.push_back(SA::construct_from_utf8("ent4"));
      expectedResult.push_back(SA::construct_from_utf8("ent5"));
      
      std::vector<string_type> expectedResultSVG;
      expectedResultSVG.push_back(SA::construct_from_utf8("ent1"));
      expectedResultSVG.push_back(SA::construct_from_utf8("ent2"));
      expectedResultSVG.push_back(SA::construct_from_utf8("ent3"));
      expectedResultSVG.push_back(SA::construct_from_utf8("ent4"));
      expectedResultSVG.push_back(SA::construct_from_utf8("ent5"));
      expectedResultSVG.push_back(SA::construct_from_utf8("svgunit"));
      expectedResultSVG.push_back(SA::construct_from_utf8("svgtest"));
      
      std::vector<string_type> nameList;
      
      Node entity;
      doc = (Document) baseT::load("staff", false);
      docType = doc.getDoctype();
      baseT::assertNotNull(docType, __LINE__, __FILE__);
      entityList = docType.getEntities();
      baseT::assertNotNull(entityList, __LINE__, __FILE__);
      entity = entityList.getNamedItem(SA::construct_from_utf8("ent5"));
      baseT::skipIfNull(entity);
      for (unsigned int indexN65667 = 0; indexN65667 != entityList.getLength(); indexN65667++) {
          entity = (Node) entityList.item(indexN65667);
    name = entity.getNodeName();
      nameList.push_back(name);
        }
      
      if (("image/svg+xml" == baseT::getContentType())) {
          baseT::assertEquals(expectedResultSVG, nameList, __LINE__, __FILE__);
  } else {
          baseT::assertEquals(expectedResult, nameList, __LINE__, __FILE__);
  }
        
    
   }
  
   /*
    *  Gets URI that identifies the test.
    */
   std::string getTargetURI() const
   {
      return "http://www.w3.org/2001/DOM-Test-Suite/level1/core/documenttypegetentities";
   }
};

#endif
