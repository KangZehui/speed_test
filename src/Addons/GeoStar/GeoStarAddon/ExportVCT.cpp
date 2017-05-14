#include "StdAfx.h"
#include "ExportVCT.h"


std::string FromUtf8(const char* str)
{
	return GeoStar::Utility::GsCW2A(GeoStar::Utility::GsCA2W(str,GeoStar::Utility::eCP_UTF8).m_WStr).m_Str;
}
ExportVCT::ExportVCT(void)
{
	m_strName = "����VCTʸ�����ݸ�ʽ";
	m_strDescription = "����VCTʸ�����ݸ�ʽ";
	
	m_eType = GIS::eExport;
}
ExportVCT::~ExportVCT(void)
{
}
VCT_GEOMETRY_TYPE GPKGToGeo(const char* strGeo)
{
	if(stricmp(strGeo,"POINT")==0)
		return VCT_POINT;
	if(stricmp(strGeo,"LINESTRING")==0)
		return VCT_LINE;
	if(stricmp(strGeo,"MULTIPOLYGON")==0)
		return VCT_POLYGON;

	return VCT_POINT;
}
class CReadFeature:public gpkg::feature
{
	VCT_GEOMETRY_TYPE m_gType;
	int m_nGeoIndex;

	VCTPoint m_Point;
	VCTLine  m_Line;
	VCTPolygon m_Polygon;
	VCTSolid m_Solid;
	VCTAnnotation  m_Ann;
	VCTAttributeRow m_Row;
	GeoStar::Kernel::GsWKBOGCReader m_Reader;
	VCTFeatureCode m_Code;
	VCTID& m_ID;
public:
	CReadFeature(int nFieldCount,VCT_GEOMETRY_TYPE gType,int nGeoIndex,VCTFeatureCode &code,VCTID& ID):m_ID(ID)
	{
		m_nGeoIndex = nGeoIndex;
		m_gType = gType;
		m_Row.vecstrFieldValues.resize(nFieldCount);

		m_Point.ObjHeader.strStyle = code.strName;
		m_Point.ObjHeader.strUserID = code.strName;

		m_Line.ObjHeader.strStyle = code.strName;
		m_Line.ObjHeader.strUserID = code.strName;

		m_Polygon.ObjHeader.strStyle = code.strName;
		m_Polygon.ObjHeader.strUserID = code.strName;

		m_Solid.ObjHeader.strStyle = code.strName;
		m_Solid.ObjHeader.strUserID = code.strName;

		m_Ann.ObjHeader.strStyle = code.strName;
		m_Ann.ObjHeader.strUserID = code.strName;

	}
public:
	/// \brief ���õ����fid
	virtual void fid(long long id)
	{
		m_Row.nOID  = id;
	}
	/// \brief ��ȡ�����fid
	virtual long long fid()
	{
		return 0;
	}
		
	/// \brief geometry�����ݳ���
	virtual int geometry_length()
	{
		return 0;
	}
	/// \brief ��ȡgeometry������ͷָ��
	virtual gpkg::geo_package_binary* geometry()
	{
		return NULL;
	}
	void GeometryBlobToVCT(GeoStar::Kernel::GsGeometryBlob* pBlob,std::vector<VCTPoint3D>& vec,int n = 0)
	{
		if(n <=0)
			vec.resize(pBlob->CoordinateLength() / pBlob->CoordinateDimension());
		else
			vec.resize(n);

		if(pBlob->CoordinateDimension() == 2)
		{	
			std::copy((GeoStar::Kernel::GsRawPoint*)pBlob->Coordinate(),
				(GeoStar::Kernel::GsRawPoint*)pBlob->Coordinate() + vec.size(),
				(GeoStar::Kernel::GsRawPoint3D*)(&vec[0]));
		}
		else
			memcpy(&vec[0],pBlob->Coordinate(),vec.size() * 24);

	}
	/// \brief ����geometry
	virtual void geometry(gpkg::geo_package_binary* geo,int nlen)
	{
		unsigned char* wkb = geo->wkb_ptr();
		m_Reader.Begin(wkb,nlen - geo->size());
		GeoStar::Kernel::GsGeometryPtr ptrGeo = m_Reader.Read();
		if(!ptrGeo)
			return ; 

		switch(ptrGeo->GeometryType())
		{ 
		/// \brief ����
		case GeoStar::Kernel::eGeometryTypePoint:
		
			m_Point.vecPoint.clear();
			m_Point.FeatureType = VCT_POINT_DEFAULT;
			GeometryBlobToVCT(ptrGeo->GeometryBlobPtr(),m_Point.vecPoint,1);
			break;
		case GeoStar::Kernel::eGeometryTypeMultiPoint:
			m_Point.vecPoint.clear();
			m_Point.FeatureType = VCT_POINT_GROUP;
			GeometryBlobToVCT(ptrGeo->GeometryBlobPtr(),m_Point.vecPoint,1);
		break;
			/// \brief ������
		case GeoStar::Kernel::eGeometryTypePath:
		/// \brief �����߶�
		case GeoStar::Kernel::eGeometryTypeLine:
			{
				m_Line.FeatureType = VCT_LINE_DIRECT;
				m_Line.vecLineData.clear();
				m_Line.vecLineData.push_back(VCTLineElement());
				m_Line.vecLineData.back().GeometryType = VCT_LINE_SIMPLE;
				GeometryBlobToVCT(ptrGeo->GeometryBlobPtr(),m_Line.vecLineData.back().vecArcPoint);

			}
			break;
		/// \brief �����
		case GeoStar::Kernel::eGeometryTypePolygon:
			{
				m_Polygon.FeatureType = VCT_POLYGON_DIRECT;
				m_Polygon.vecPolygonElement.clear();
				GeoStar::Kernel::GsPolygonPtr ptrPolygon = ptrGeo;
				for(int i =0;i<ptrPolygon->Count();i++)
				{
					m_Polygon.vecPolygonElement.push_back(VCTPolygonElement());

					m_Polygon.vecPolygonElement.back().GeoType = VCT_POLYGON_SIMPLE;
					GeometryBlobToVCT(ptrPolygon->Geometry(i)->GeometryBlobPtr(),m_Polygon.vecPolygonElement.back().vecPoints);
				} 
			}
			break;

		 
		/// \brief �������
		case GeoStar::Kernel::eGeometryTypePolyline: 
			{
				m_Line.FeatureType = VCT_LINE_DIRECT;
				m_Line.vecLineData.clear();
				GeoStar::Kernel::GsPolylinePtr ptrPolyline = ptrGeo;
				for(int i =0;i<ptrPolyline->Count();i++)
				{
					m_Line.vecLineData.push_back(VCTLineElement());

					m_Line.vecLineData.back().GeometryType = VCT_LINE_SIMPLE;
					GeometryBlobToVCT(ptrPolyline->Geometry(i)->GeometryBlobPtr(),m_Line.vecLineData.back().vecArcPoint);
				} 
			}
			break;

			 
		/// \brief ��Ȧ
		case GeoStar::Kernel::eGeometryTypeRing:
			{
				m_Polygon.FeatureType = VCT_POLYGON_DIRECT;
				m_Polygon.vecPolygonElement.clear();
				m_Polygon.vecPolygonElement.push_back(VCTPolygonElement());
				m_Polygon.vecPolygonElement.back().GeoType = VCT_POLYGON_SIMPLE;
				GeometryBlobToVCT(ptrGeo->GeometryBlobPtr(),m_Polygon.vecPolygonElement.back().vecPoints);
				
			}
			break;
		}

	}
	void Write(VCTFeatureWriter &w)
	{
		m_Row.nOID = m_ID++;
		if(m_gType == VCT_POINT)
		{
			m_Point.ObjHeader.nObjID = m_Row.nOID;
			w.Write(m_Point);
		}
		else if(m_gType == VCT_LINE)
		{
			m_Line.ObjHeader.nObjID = m_Row.nOID;
			w.Write(m_Line);
		}
		else if(m_gType == VCT_POLYGON)
		{
			m_Polygon.ObjHeader.nObjID = m_Row.nOID;
			w.Write(m_Polygon);
		}
		
		w.Write(m_Row);
	}


	/// \brief ��ȡĳ�еĵ��������ֶ�ֵ
	virtual long long int_value(int col)
	{
		return 0;
	}
	/// \brief ��ȡĳ�еĵ��︡���ֶ�ֵ
	virtual double float_value(int col)
	{
		return 0;
	}
	/// \brief ��ȡĳ�еĵ����ַ����ֶ�ֵ
	virtual const char* string_value(int col)
	{
		return NULL;
	}

	/// \brief ��ȡĳ�еĵ��������ֶ�ֵ
	virtual void value(int col,long long val)
	{ 
		std::stringstream ss;
		ss<<val;
		value(col,ss.str().c_str());
	}
	/// \brief ��ȡĳ�еĵ��︡���ֶ�ֵ
	virtual void value(int col,double val)
	{
		std::stringstream ss;
		ss<<std::setprecision(10)<<val;
		value(col,ss.str().c_str());
	}
	/// \brief ��ȡĳ�еĵ����ַ����ֶ�ֵ
	virtual void value(int col,const char * val)
	{
		if(col < m_nGeoIndex)
			col--;
		else
			col-=2;
		if(val)
			m_Row.vecstrFieldValues[col] = val;
		else
			m_Row.vecstrFieldValues[col].clear();

	}

};
//���ݿռ�ο�
void PrepareHead(VCTHead& head,gpkg::content& content,gpkg::spatial_ref& ref)
{
	head.dfMinX = min(head.dfMinX, content.min_x);
	head.dfMaxX = max(head.dfMaxX, content.max_x);

	head.dfMinY = min(head.dfMinY, content.min_y);
	head.dfMaxY = max(head.dfMaxY, content.max_y);

	GeoStar::Kernel::GsSpatialReferencePtr ptrSR;
	if(!ref.definition.empty())
		ptrSR = new GeoStar::Kernel::GsSpatialReference(ref.definition.c_str());
	else if(ref.srs_id>0)
		ptrSR = new GeoStar::Kernel::GsSpatialReference(ref.srs_id);
	else
		ptrSR = new GeoStar::Kernel::GsSpatialReference(4326);
	if(ptrSR->Units() == GeoStar::Kernel::eMeter)
	{
		head.chCoordSysType = 'M';
		head.chUnit = 'M';
		head.strXYUnit = "M";
	}
	else if(ptrSR->Units() == GeoStar::Kernel::eDegree)
	{
		head.strXYUnit = "D";
		head.chUnit = 'D';
		head.chCoordSysType = 'D';
	}
	head.strProjection = FromUtf8(ptrSR->Projection().c_str());
	head.strSpheroid = FromUtf8(ptrSR->Ellipsoid().c_str());

	time_t t = time(NULL);
	tm  gm = *localtime(&t);

	std::stringstream ss;
	ss<<(gm.tm_year + 1900)<<std::setw(2)<<std::setfill('0')<<(gm.tm_mon + 1)<<gm.tm_mday;
	head.strDate = ss.str();
}

//�����VCT�ļ��С�
void ExportVCT::WriteTo(VCTWriter& w,gpkg::content& content,gpkg::database_ptr db,GIS::Progress * pProgress,VCTID& id)
{
	//�򿪵������
	gpkg::feature_table_ptr ptrFeaClass = db->open_feature_table(content.table_name.c_str());
	if(!ptrFeaClass)
	{
		std::stringstream ss;
		ss<<"�������"<<content.table_name<<"��ʧ��";
		pProgress->OnLog(ss.str().c_str(),GIS::LogLevel::eError);
		return ;
	}
	//׼����VCT��ͷ��
	PrepareHead(w.Head(),content,db->spatial_ref_table()->query(content.srs_id));

	//��ü������͡�
	gpkg::geometry_column geo =  db->geometry_columns_table()->query(content.table_name.c_str());
	VCTFeatureCode code;
	code.GeometryType = GPKGToGeo(geo.geometry_type_name.c_str());
	code.strName = FromUtf8(content.identifier.c_str());
	code.strUserID = code.strName;
	code.strAttributeTableName = code.strName;
	//���ṹ
	VCTTableStructure tab;
	tab.strTableName = code.strUserID;
	

	//��ȡ�ֶνṹ��
	std::vector<gpkg::field> vecField = ptrFeaClass->fields();
	std::vector<gpkg::field>::iterator it = vecField.begin();
	//�����ֶε�����
	int nGeoFieldIndex  = -1;
	for(;it != vecField.end();it++)
	{
		if(it == vecField.begin()) //�������ֶΣ���Ϊ�����FID
			continue;

		//�������е��ֶΡ�
		switch(it->type)
		{
		case gpkg::BOOLEAN:
			tab.vecFields.push_back(VCTField(it->name.c_str(),VCT_BOOL));
			break;
		case gpkg::TINYINT:
			tab.vecFields.push_back(VCTField(it->name.c_str(),VCT_SMALLINT));
			break;
		case gpkg::MEDIUMINT:
			tab.vecFields.push_back(VCTField(it->name.c_str(),VCT_INTEGER));
			break;
		case gpkg::INTEGER: 
			tab.vecFields.push_back(VCTField(it->name.c_str(),VCT_INTEGER));
			break;
		case gpkg::FLOAT:
			tab.vecFields.push_back(VCTField(it->name.c_str(),VCT_FLOAT,10,8));
			break;
		case gpkg::DOUBLE: 
			tab.vecFields.push_back(VCTField(it->name.c_str(),VCT_FLOAT,38,10));
			break;
		case gpkg::TEXT:
			tab.vecFields.push_back(VCTField(it->name.c_str(),VCT_CHAR,1024,0));
			break;
		case gpkg::BLOB:
			tab.vecFields.push_back(VCTField(it->name.c_str(),VCT_VARBIN));
			break;
		case gpkg::DATE:
			tab.vecFields.push_back(VCTField(it->name.c_str(),VCT_DATE));
			break;
		case gpkg::DATETIME:
			tab.vecFields.push_back(VCTField(it->name.c_str(),VCT_DATETIME));
			break;

		case gpkg::POINT:
		case gpkg::LINESTRING:
		case gpkg::MULTIPOLYGON:
			nGeoFieldIndex = (it - vecField.begin());
			continue;
			break;
		default:
			tab.vecFields.push_back(VCTField(it->name.c_str(),VCT_CHAR,1024,0));
			break;

		}
	}

	//��ʼд��һ�������ࡣ
	VCTFeatureWriter writer = w.BeginFeature(code,tab);

	//�����������
	long nMax = ptrFeaClass->count();
	//���ÿչ���������
	ptrFeaClass->filter();
	CReadFeature fea(tab.vecFields.size(),code.GeometryType,nGeoFieldIndex,code,id);
	int nPos  = 0;
	std::string strTitle = "ת������";
	std::string strContent = code.strName;
	while(ptrFeaClass->next(&fea))
	{
		//д�뵽vct��
		fea.Write(writer);
		nPos++;
		pProgress->OnProgress(nPos,nMax,strTitle.c_str(),strContent.c_str());
	}

}
/// \brief ִ�в��
const char* ExportVCT::Execute(const char* strParameter,GIS::Progress * pProgress)
{
	pProgress->OnLog("׼�����ݵ���",GIS::LogLevel::eInfo);
	pProgress->OnLog("�����������",GIS::LogLevel::eInfo);

	//�������
	KVParameter kvp(strParameter);
	if(kvp.Error())
	{
		pProgress->OnLog("���������������",GIS::LogLevel::eError);
		return NULL;
	}
	//�����geopackage�ļ���
	std::string strInput = kvp.Value("Input");
	if(strInput.empty())
	{
		pProgress->OnLog("û����������·����",GIS::LogLevel::eError);
		return NULL;
	}

	//���VCT�ļ���
	std::string strOutFile = kvp.Value("Path");
	if(strOutFile.empty())
	{
		pProgress->OnLog("û����������ļ�",GIS::LogLevel::eError);
		return NULL;
	}

	std::string strLog = "ת����׼��ʽʸ������ΪVCTʸ�����ݴ�";
	strLog+=strInput;
	strLog+="��";
	strLog+=strOutFile;
	pProgress->OnLog(strLog.c_str(),GIS::LogLevel::eInfo);
	 
	GeoStar::Utility::GsFile file(strInput.c_str());
	if(!file.Exists())
	{
		pProgress->OnLog("����·�������ڡ�",GIS::LogLevel::eError);
		return NULL;
	}
	
	//��ȡ������չ��
	string strExt = strOutFile.substr(strOutFile.length() - 4);
	
	//�������VCTΪ��չ�����ļ����ʶ�����������VCT�ļ��С�
	bool bSingleVCT = (stricmp(strExt.c_str(),".vct")==0);

	std::string strUtf8Path =	GeoStar::Utility::GsCW2A(GeoStar::Utility::GsCA2W(strInput.c_str()).m_WStr,
								GeoStar::Utility::eCP_UTF8).m_Str;
	//���������ݿ⡣
	gpkg::database_ptr db(new gpkg::database(strUtf8Path.c_str(),false));
	pProgress->OnLog("��������ݼ�",GIS::LogLevel::eInfo);
	
	//ö�����е�feature
	std::vector<gpkg::content> vecContent = db->contents_table()->query("features");
	std::vector<gpkg::content>::iterator it = vecContent.begin();
	VCTID id = 1;
	if(bSingleVCT)
	{
		VCTWriter w(strOutFile.c_str());
		for(;it != vecContent.end();it++)
		{
			WriteTo(w,*it,db,pProgress,id);
		}

		//�������ơ�
		pProgress->OnLog("�ύ���ݡ�",GIS::LogLevel::eInfo);
		w.Finish();
	}
	else //����ǵ����ļ��Ļ���ÿ�����������һ���ļ���
	{
		for(;it != vecContent.end();it++)
		{
			string strFileName = it->table_name.c_str();
			strFileName+=".vct";
			strFileName = GeoStar::Utility::GsFileSystem::Combine(strOutFile.c_str(),strFileName.c_str());

			VCTWriter w(strFileName.c_str());
			WriteTo(w,*it,db,pProgress,id);
			pProgress->OnLog("�ύ���ݡ�",GIS::LogLevel::eInfo);
		
			w.Finish();
		}
	}

	return NULL;
}