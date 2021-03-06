#ifndef _ALTOVA_INCLUDED_gie_ALTOVA_gmd_ALTOVA_CMD_PortrayalCatalogueReference_Type
#define _ALTOVA_INCLUDED_gie_ALTOVA_gmd_ALTOVA_CMD_PortrayalCatalogueReference_Type

#include "type_gco.CAbstractObject_Type.h"


namespace gie
{

namespace gmd
{	

class CMD_PortrayalCatalogueReference_Type : public ::gie::gco::CAbstractObject_Type
{
public:
	gie_EXPORT CMD_PortrayalCatalogueReference_Type(xercesc::DOMNode* const& init);
	gie_EXPORT CMD_PortrayalCatalogueReference_Type(CMD_PortrayalCatalogueReference_Type const& init);
	void operator=(CMD_PortrayalCatalogueReference_Type const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_gmd_altova_CMD_PortrayalCatalogueReference_Type); }
	MemberElement<gmd::CCI_Citation_PropertyType, _altova_mi_gmd_altova_CMD_PortrayalCatalogueReference_Type_altova_portrayalCatalogueCitation> portrayalCatalogueCitation;
	struct portrayalCatalogueCitation { typedef Iterator<gmd::CCI_Citation_PropertyType> iterator; };
	gie_EXPORT void SetXsiType();
};



} // namespace gmd

}	// namespace gie

#endif // _ALTOVA_INCLUDED_gie_ALTOVA_gmd_ALTOVA_CMD_PortrayalCatalogueReference_Type
