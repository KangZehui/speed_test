#ifndef _ALTOVA_INCLUDED_gie_ALTOVA_gml_ALTOVA_CPrimeMeridianPropertyType
#define _ALTOVA_INCLUDED_gie_ALTOVA_gml_ALTOVA_CPrimeMeridianPropertyType



namespace gie
{

namespace gml
{	

class CPrimeMeridianPropertyType : public TypeBase
{
public:
	gie_EXPORT CPrimeMeridianPropertyType(xercesc::DOMNode* const& init);
	gie_EXPORT CPrimeMeridianPropertyType(CPrimeMeridianPropertyType const& init);
	void operator=(CPrimeMeridianPropertyType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_gml_altova_CPrimeMeridianPropertyType); }

	MemberAttribute<string_type,_altova_mi_gml_altova_CPrimeMeridianPropertyType_altova_type, 0, 0> type;	// type Cstring

	MemberAttribute<string_type,_altova_mi_gml_altova_CPrimeMeridianPropertyType_altova_href, 0, 0> href;	// href CanyURI

	MemberAttribute<string_type,_altova_mi_gml_altova_CPrimeMeridianPropertyType_altova_role, 0, 0> role;	// role CanyURI

	MemberAttribute<string_type,_altova_mi_gml_altova_CPrimeMeridianPropertyType_altova_arcrole, 0, 0> arcrole;	// arcrole CanyURI

	MemberAttribute<string_type,_altova_mi_gml_altova_CPrimeMeridianPropertyType_altova_title, 0, 0> title;	// title Cstring
	MemberAttribute<string_type,_altova_mi_gml_altova_CPrimeMeridianPropertyType_altova_show, 0, 5> show;	// show CshowType
	MemberAttribute<string_type,_altova_mi_gml_altova_CPrimeMeridianPropertyType_altova_actuate, 0, 4> actuate;	// actuate CactuateType
	MemberAttribute<string_type,_altova_mi_gml_altova_CPrimeMeridianPropertyType_altova_nilReason, 1, 5> nilReason;	// nilReason CNilReasonType

	MemberAttribute<string_type,_altova_mi_gml_altova_CPrimeMeridianPropertyType_altova_remoteSchema, 0, 0> remoteSchema;	// remoteSchema CanyURI
	MemberElement<gml::CPrimeMeridianType, _altova_mi_gml_altova_CPrimeMeridianPropertyType_altova_PrimeMeridian> PrimeMeridian;
	struct PrimeMeridian { typedef Iterator<gml::CPrimeMeridianType> iterator; };
	gie_EXPORT void SetXsiType();
};



} // namespace gml

}	// namespace gie

#endif // _ALTOVA_INCLUDED_gie_ALTOVA_gml_ALTOVA_CPrimeMeridianPropertyType