#ifndef _ALTOVA_INCLUDED_gie_ALTOVA_gmd_ALTOVA_CDS_Series_Type
#define _ALTOVA_INCLUDED_gie_ALTOVA_gmd_ALTOVA_CDS_Series_Type

#include "type_gmd.CAbstractDS_Aggregate_Type.h"


namespace gie
{

namespace gmd
{	

class CDS_Series_Type : public ::gie::gmd::CAbstractDS_Aggregate_Type
{
public:
	gie_EXPORT CDS_Series_Type(xercesc::DOMNode* const& init);
	gie_EXPORT CDS_Series_Type(CDS_Series_Type const& init);
	void operator=(CDS_Series_Type const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_gmd_altova_CDS_Series_Type); }
	gie_EXPORT void SetXsiType();
};



} // namespace gmd

}	// namespace gie

#endif // _ALTOVA_INCLUDED_gie_ALTOVA_gmd_ALTOVA_CDS_Series_Type