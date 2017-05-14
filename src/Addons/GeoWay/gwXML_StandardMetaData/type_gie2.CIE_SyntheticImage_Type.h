#ifndef _ALTOVA_INCLUDED_gie_ALTOVA_gie2_ALTOVA_CIE_SyntheticImage_Type
#define _ALTOVA_INCLUDED_gie_ALTOVA_gie2_ALTOVA_CIE_SyntheticImage_Type

#include "type_gie2.CAbstractIE_Imagery_Type.h"


namespace gie
{

namespace gie2
{	

class CIE_SyntheticImage_Type : public ::gie::gie2::CAbstractIE_Imagery_Type
{
public:
	gie_EXPORT CIE_SyntheticImage_Type(xercesc::DOMNode* const& init);
	gie_EXPORT CIE_SyntheticImage_Type(CIE_SyntheticImage_Type const& init);
	void operator=(CIE_SyntheticImage_Type const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_gie2_altova_CIE_SyntheticImage_Type); }
	MemberElement<gmd::CMD_Usage_PropertyType, _altova_mi_gie2_altova_CIE_SyntheticImage_Type_altova_intendedUse> intendedUse;
	struct intendedUse { typedef Iterator<gmd::CMD_Usage_PropertyType> iterator; };
	gie_EXPORT void SetXsiType();
};



} // namespace gie2

}	// namespace gie

#endif // _ALTOVA_INCLUDED_gie_ALTOVA_gie2_ALTOVA_CIE_SyntheticImage_Type