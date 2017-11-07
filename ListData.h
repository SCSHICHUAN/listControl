



class ListData :public CObject {
	DECLARE_SERIAL(ListData);
public:
	CString m_equmentData;
	CString m_photoPathData;
public:
	ListData() {};
	ListData(CString m_equment,CString m_photoPath)
	{
		m_equmentData = m_equment;
		m_photoPathData = m_photoPath;
	}
	void Serialize(CArchive& ar);	
};