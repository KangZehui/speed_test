#ifndef _ALTOVA_INCLUDED_gie_ALTOVA_gmd_ALTOVA_CMD_BrowseGraphic_Type
#define _ALTOVA_INCLUDED_gie_ALTOVA_gmd_ALTOVA_CMD_BrowseGraphic_Type

#include "type_gco.CAbstractObject_Type.h"


namespace gie
{

namespace gmd
{	

class CMD_BrowseGraphic_Type : public ::gie::gco::CAbstractObject_Type
{
public:
	gie_EXPORT CMD_BrowseGraphic_Type(xercesc::DOMNode* const& init);
	gie_EXPORT CMD_BrowseGraphic_Type(CMD_BrowseGraphic_Type const& init);
	void operator=(CMD_BrowseGraphic_Type const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_gmd_altova_CMD_BrowseGraphic_Type); }
	MemberElement<gco::CCharacterString_PropertyType, _altova_mi_gmd_altova_CMD_BrowseGraphic_Type_altova_fileName> fileName;
	struct fileName { typedef Iterator<gco::CCharacterString_PropertyType> iterator; };
	MemberElement<gco::CCharacterString_PropertyType, _altova_mi_gmd_altova_CMD_BrowseGraphic_Type_altova_fileDescription> fileDescription;
	struct fileDescription { typedef Iterator<gco::CCharacterString_PropertyType> iterator; };
	MemberElement<gco::CCharacterString_PropertyType, _altova_mi_gmd_altova_CMD_BrowseGraphic_Type_altova_fileType> fileType;
	struct fileType { typedef Iterator<gco::CCharacterString_PropertyType> iterator; };
	gie_EXPORT void SetXsiType();
};



} // namespace gmd

}	// namespace gie

#endif // _ALTOVA_INCLUDED_gie_ALTOVA_gmd_ALTOVA_CMD_BrowseGraphic_Type
