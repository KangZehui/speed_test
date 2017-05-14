#ifndef _ALTOVA_INCLUDED_gie_ALTOVA_gml_ALTOVA_CintegerOrNilReasonType
#define _ALTOVA_INCLUDED_gie_ALTOVA_gml_ALTOVA_CintegerOrNilReasonType



namespace gie
{

namespace gml
{	

class CintegerOrNilReasonType : public TypeBase
{
public:
	gie_EXPORT CintegerOrNilReasonType(xercesc::DOMNode* const& init);
	gie_EXPORT CintegerOrNilReasonType(CintegerOrNilReasonType const& init);
	void operator=(CintegerOrNilReasonType const& other) { m_node = other.m_node; }
	static altova::meta::SimpleType StaticInfo() { return altova::meta::SimpleType(types + _altova_ti_gml_altova_CintegerOrNilReasonType); }

	enum EnumValues {
		Invalid = -1,
		k_inapplicable = 0, // inapplicable
		k_missing = 1, // missing
		k_template = 2, // template
		k_unknown = 3, // unknown
		k_withheld = 4, // withheld
		EnumValueCount
	};
	void operator= (const string_type& value) 
	{
		altova::XmlFormatter* Formatter = static_cast<altova::XmlFormatter*>(altova::AnySimpleTypeFormatter);
		XercesTreeOperations::SetValue(GetNode(), Formatter->Format(value));
	}	
		
	operator string_type()
	{
		return CastAs<string_type >::Do(GetNode(), 0);
	}
};



} // namespace gml

}	// namespace gie

#endif // _ALTOVA_INCLUDED_gie_ALTOVA_gml_ALTOVA_CintegerOrNilReasonType
