#ifndef _ALTOVA_INCLUDED_gie_ALTOVA_xs_ALTOVA_CunsignedInt
#define _ALTOVA_INCLUDED_gie_ALTOVA_xs_ALTOVA_CunsignedInt



namespace gie
{

namespace xs
{	

class CunsignedInt : public TypeBase
{
public:
	gie_EXPORT CunsignedInt(xercesc::DOMNode* const& init);
	gie_EXPORT CunsignedInt(CunsignedInt const& init);
	void operator=(CunsignedInt const& other) { m_node = other.m_node; }
	static altova::meta::SimpleType StaticInfo() { return altova::meta::SimpleType(types + _altova_ti_xs_altova_CunsignedInt); }
	void operator= (const unsigned& value) 
	{
		altova::XmlFormatter* Formatter = static_cast<altova::XmlFormatter*>(altova::IntegerFormatter);
		XercesTreeOperations::SetValue(GetNode(), Formatter->Format(value));
	}	
		
	operator unsigned()
	{
		return CastAs<unsigned >::Do(GetNode(), 0);
	}
};



} // namespace xs

}	// namespace gie

#endif // _ALTOVA_INCLUDED_gie_ALTOVA_xs_ALTOVA_CunsignedInt
