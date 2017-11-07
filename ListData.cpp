#include "stdafx.h"
#include "ListData.h"

IMPLEMENT_SERIAL(ListData, CObject, 1 | VERSIONABLE_SCHEMA);//´®ÐÐ»¯°æ±¾

void ListData::Serialize(CArchive &ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << m_equmentData << m_photoPathData;
	}
	else {
		UINT nSchema = ar.GetObjectSchema();
		switch (nSchema)
		{
		case 1:
			ar >> m_equmentData >> m_photoPathData;
		default:
			AfxThrowArchiveException(CArchiveException::badSchema);
		}
	}

}