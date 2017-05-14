#ifndef _ALTOVA_INCLUDED_gie_ALTOVA_gml_ALTOVA_CLocationPropertyType
#define _ALTOVA_INCLUDED_gie_ALTOVA_gml_ALTOVA_CLocationPropertyType



namespace gie
{

namespace gml
{	

class CLocationPropertyType : public TypeBase
{
public:
	gie_EXPORT CLocationPropertyType(xercesc::DOMNode* const& init);
	gie_EXPORT CLocationPropertyType(CLocationPropertyType const& init);
	void operator=(CLocationPropertyType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_gml_altova_CLocationPropertyType); }

	MemberAttribute<string_type,_altova_mi_gml_altova_CLocationPropertyType_altova_type, 0, 0> type;	// type Cstring

	MemberAttribute<string_type,_altova_mi_gml_altova_CLocationPropertyType_altova_href, 0, 0> href;	// href CanyURI

	MemberAttribute<string_type,_altova_mi_gml_altova_CLocationPropertyType_altova_role, 0, 0> role;	// role CanyURI

	MemberAttribute<string_type,_altova_mi_gml_altova_CLocationPropertyType_altova_arcrole, 0, 0> arcrole;	// arcrole CanyURI

	MemberAttribute<string_type,_altova_mi_gml_altova_CLocationPropertyType_altova_title, 0, 0> title;	// title Cstring
	MemberAttribute<string_type,_altova_mi_gml_altova_CLocationPropertyType_altova_show, 0, 5> show;	// show CshowType
	MemberAttribute<string_type,_altova_mi_gml_altova_CLocationPropertyType_altova_actuate, 0, 4> actuate;	// actuate CactuateType
	MemberAttribute<string_type,_altova_mi_gml_altova_CLocationPropertyType_altova_nilReason, 1, 5> nilReason;	// nilReason CNilReasonType

	MemberAttribute<string_type,_altova_mi_gml_altova_CLocationPropertyType_altova_remoteSchema, 0, 0> remoteSchema;	// remoteSchema CanyURI
	MemberElement<gml::CCompositeCurveType, _altova_mi_gml_altova_CLocationPropertyType_altova_CompositeCurve> CompositeCurve;
	struct CompositeCurve { typedef Iterator<gml::CCompositeCurveType> iterator; };
	MemberElement<gml::CCompositeSolidType, _altova_mi_gml_altova_CLocationPropertyType_altova_CompositeSolid> CompositeSolid;
	struct CompositeSolid { typedef Iterator<gml::CCompositeSolidType> iterator; };
	MemberElement<gml::CCompositeSurfaceType, _altova_mi_gml_altova_CLocationPropertyType_altova_CompositeSurface> CompositeSurface;
	struct CompositeSurface { typedef Iterator<gml::CCompositeSurfaceType> iterator; };
	MemberElement<gml::CCurveType, _altova_mi_gml_altova_CLocationPropertyType_altova_Curve> Curve;
	struct Curve { typedef Iterator<gml::CCurveType> iterator; };
	MemberElement<gml::CGeometricComplexType, _altova_mi_gml_altova_CLocationPropertyType_altova_GeometricComplex> GeometricComplex;
	struct GeometricComplex { typedef Iterator<gml::CGeometricComplexType> iterator; };
	MemberElement<gml::CGridType, _altova_mi_gml_altova_CLocationPropertyType_altova_Grid> Grid;
	struct Grid { typedef Iterator<gml::CGridType> iterator; };
	MemberElement<gml::CLineStringType, _altova_mi_gml_altova_CLocationPropertyType_altova_LineString> LineString;
	struct LineString { typedef Iterator<gml::CLineStringType> iterator; };
	MemberElement<gml::CMultiCurveType, _altova_mi_gml_altova_CLocationPropertyType_altova_MultiCurve> MultiCurve;
	struct MultiCurve { typedef Iterator<gml::CMultiCurveType> iterator; };
	MemberElement<gml::CMultiGeometryType, _altova_mi_gml_altova_CLocationPropertyType_altova_MultiGeometry> MultiGeometry;
	struct MultiGeometry { typedef Iterator<gml::CMultiGeometryType> iterator; };
	MemberElement<gml::CMultiPointType, _altova_mi_gml_altova_CLocationPropertyType_altova_MultiPoint> MultiPoint;
	struct MultiPoint { typedef Iterator<gml::CMultiPointType> iterator; };
	MemberElement<gml::CMultiSolidType, _altova_mi_gml_altova_CLocationPropertyType_altova_MultiSolid> MultiSolid;
	struct MultiSolid { typedef Iterator<gml::CMultiSolidType> iterator; };
	MemberElement<gml::CMultiSurfaceType, _altova_mi_gml_altova_CLocationPropertyType_altova_MultiSurface> MultiSurface;
	struct MultiSurface { typedef Iterator<gml::CMultiSurfaceType> iterator; };
	MemberElement<gml::COrientableCurveType, _altova_mi_gml_altova_CLocationPropertyType_altova_OrientableCurve> OrientableCurve;
	struct OrientableCurve { typedef Iterator<gml::COrientableCurveType> iterator; };
	MemberElement<gml::COrientableSurfaceType, _altova_mi_gml_altova_CLocationPropertyType_altova_OrientableSurface> OrientableSurface;
	struct OrientableSurface { typedef Iterator<gml::COrientableSurfaceType> iterator; };
	MemberElement<gml::CPointType, _altova_mi_gml_altova_CLocationPropertyType_altova_Point> Point;
	struct Point { typedef Iterator<gml::CPointType> iterator; };
	MemberElement<gml::CPolygonType, _altova_mi_gml_altova_CLocationPropertyType_altova_Polygon> Polygon;
	struct Polygon { typedef Iterator<gml::CPolygonType> iterator; };
	MemberElement<gml::CPolyhedralSurfaceType, _altova_mi_gml_altova_CLocationPropertyType_altova_PolyhedralSurface> PolyhedralSurface;
	struct PolyhedralSurface { typedef Iterator<gml::CPolyhedralSurfaceType> iterator; };
	MemberElement<gml::CRectifiedGridType, _altova_mi_gml_altova_CLocationPropertyType_altova_RectifiedGrid> RectifiedGrid;
	struct RectifiedGrid { typedef Iterator<gml::CRectifiedGridType> iterator; };
	MemberElement<gml::CSolidType, _altova_mi_gml_altova_CLocationPropertyType_altova_Solid> Solid;
	struct Solid { typedef Iterator<gml::CSolidType> iterator; };
	MemberElement<gml::CSurfaceType, _altova_mi_gml_altova_CLocationPropertyType_altova_Surface> Surface;
	struct Surface { typedef Iterator<gml::CSurfaceType> iterator; };
	MemberElement<gml::CTinType, _altova_mi_gml_altova_CLocationPropertyType_altova_Tin> Tin;
	struct Tin { typedef Iterator<gml::CTinType> iterator; };
	MemberElement<gml::CTriangulatedSurfaceType, _altova_mi_gml_altova_CLocationPropertyType_altova_TriangulatedSurface> TriangulatedSurface;
	struct TriangulatedSurface { typedef Iterator<gml::CTriangulatedSurfaceType> iterator; };
	MemberElement<gml::CCodeType, _altova_mi_gml_altova_CLocationPropertyType_altova_LocationKeyWord> LocationKeyWord;
	struct LocationKeyWord { typedef Iterator<gml::CCodeType> iterator; };
	MemberElement<gml::CStringOrRefType, _altova_mi_gml_altova_CLocationPropertyType_altova_LocationString> LocationString;
	struct LocationString { typedef Iterator<gml::CStringOrRefType> iterator; };
	MemberElement<gml::CNilReasonTypeType, _altova_mi_gml_altova_CLocationPropertyType_altova_Null> Null;
	struct Null { typedef Iterator<gml::CNilReasonTypeType> iterator; };
	gie_EXPORT void SetXsiType();
};



} // namespace gml

}	// namespace gie

#endif // _ALTOVA_INCLUDED_gie_ALTOVA_gml_ALTOVA_CLocationPropertyType
