
// DrowListControlitemDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DrowListControlitem.h"
#include "DrowListControlitemDlg.h"
#include "afxdialogex.h"

#include"ListItem.h"

#include<iostream>
#include<fstream>

using namespace std;

#include<gdiplus.h>
using namespace Gdiplus;

#include"Model.h"
#include"ListData.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDrowListControlitemDlg 对话框



CDrowListControlitemDlg::CDrowListControlitemDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DROWLISTCONTROLITEM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDrowListControlitemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, m_list);//将你定义的listContr，以stroryBoard
}

BEGIN_MESSAGE_MAP(CDrowListControlitemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CDrowListControlitemDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDrowListControlitemDlg::OnBnClickedButton2)
	ON_NOTIFY(HDN_FILTERBTNCLICK, 0, &CDrowListControlitemDlg::F)
//	ON_NOTIFY(NM_HOVER, IDC_LIST3, &CDrowListControlitemDlg::OnNMHoverList3)
	ON_NOTIFY(NM_CLICK, IDC_LIST3, &CDrowListControlitemDlg::OnNMClickList3)
//	ON_NOTIFY(LVN_HOTTRACK, IDC_LIST3, &CDrowListControlitemDlg::OnLvnHotTrackList3)
//ON_NOTIFY(LVN_HOTTRACK, IDC_LIST3, &CDrowListControlitemDlg::OnLvnHotTrackList3)
ON_BN_CLICKED(IDC_BUTTON3, &CDrowListControlitemDlg::OnBnClickedButton3)
ON_BN_CLICKED(IDC_BUTTON4, &CDrowListControlitemDlg::OnBnClickedButton4)
ON_BN_CLICKED(IDC_BUTTON5, &CDrowListControlitemDlg::OnBnClickedButton5)
ON_BN_CLICKED(IDC_BUTTON6, &CDrowListControlitemDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// CDrowListControlitemDlg 消息处理程序

BOOL CDrowListControlitemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	Gdiplus::GdiplusStartup(&m_pGdiToken, &m_pGdipluStartupInput, NULL);
	
	m_list.InsertColumn(0, _T("00000"), LVCFMT_FILL, 600);
	m_list.SetItemHeight(200);

	OnBnClickedButton6();//加载本地数据
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CDrowListControlitemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDrowListControlitemDlg::OnPaint()
{
	

	
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDrowListControlitemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDrowListControlitemDlg::OnBnClickedButton1()
{
	//CDrowListControlitemDlg *pDlg = new CDrowListControlitemDlg;
	
	
	for (INT i = 0; i < 40; i++)
	{
		ModelStruct wxData = m_Equment.GetAt(i);
		m_list.InsertItem(i, _T(""));//触发重绘控件的代码
		m_list.SetItemInfo(i, wxData);
	}
	
}

//模拟网络或者本地产生数据，“就是要显示到listControl的文字和照片”
void CDrowListControlitemDlg::OnBnClickedButton2()
{
	
	
	CString SNNumberData;
	CString photoPathData;
	

	for (int i = 0; i < 40; i++)
	{
		
		ModelStruct model;
		
		SNNumberData.Format(_T("DY0900010%d"), i);
		model.SNNumber = SNNumberData;

		photoPathData.Format(_T("C:\\Users\\SHICHUAN\\Desktop\\桌面文件\\lili\\%d.jpg"), i);//照片的路径
		model.photoPath = photoPathData;

		m_Equment.Add(model);//添加数据模型model<struct>
		
	}

	
	

	//CString 转 char 
	//int len = out.GetLength();
	//char *cstr = new char[len + 1];
	//cstr[len] = 0;
	//(CP_OEMCP, 0, out, -1, cstr, len, NULL, NULL);

	
}


void CDrowListControlitemDlg::F(NMHDR *pNMHDR, LRESULT *pResult)
{
	// 此功能要求 Internet Explorer 5 或更高版本。
	// 符号 _WIN32_IE 必须是 >= 0x0500。
	LPNMHDFILTERBTNCLICK phdr = reinterpret_cast<LPNMHDFILTERBTNCLICK>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}



//listControl 某一项被点击
void CDrowListControlitemDlg::OnNMClickList3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	ModelStruct model = m_list.GetItemInfo(pNMItemActivate->iItem);
	
	CFont font;
   font.CreatePointFont(150, L"微软雅黑");
   GetDlgItem(IDC_STATIC)->SetFont(&font);
	SetDlgItemText(IDC_STATIC, model.SNNumber);
	DrowPicture(model);
	*pResult = 0;
}

void CDrowListControlitemDlg::DrowPicture(ModelStruct mode)
{
	Graphics g(this->m_hWnd);
	Image *m_image = Image::FromFile(mode.photoPath);

	CRect rcItem(700,300, 1300,800);
	g.DrawImage(m_image, rcItem.left, rcItem.top, rcItem.Width(), rcItem.Height());
	delete m_image;
}



void CDrowListControlitemDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString SNNumberData;
	CString photoPathData;

	
	CArray<ListData*, ListData*> array;


	for (int i = 0; i < 40; i++)
	{
		ModelStruct model;
		//ListData *model = new  ListData();

		SNNumberData.Format(_T("DY0900010%d"), i);
		//model->m_equmentData = SNNumberData;
		model.SNNumber = SNNumberData;

		photoPathData.Format(_T("C:\\Users\\SHICHUAN\\Desktop\\桌面文件\\lili\\%d.jpg"), i);//照片的路径
	
		//model->m_photoPathData = photoPathData;
		model.photoPath = photoPathData;

		//array.Add(model);//添加数据模型model<struct>
		m_Equment.Add(model);
	}

	CFile file(_T("array.txt"), CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store);
	m_Equment.Serialize(ar);

	

	ar.Close();
	file.Close();
	MessageBox(_T("串行化成功"));


}


void CDrowListControlitemDlg::OnBnClickedButton4()
{

	// TODO: 在此添加控件通知处理程序代码
	CFile flie(_T("array.txt"), CFile::modeRead);
	CArchive ar(&flie, CArchive::load);
	CArray<ListData*, ListData*> array;


	CArray<ModelStruct, ModelStruct&> localData;
	localData.Serialize(ar);



	CString str1;
	str1.Format(_T("%d"), localData.GetCount());
	AfxMessageBox(str1);


	for (int i = 0; i < localData.GetCount(); i++)
	{
		ModelStruct wxData = localData.GetAt(i);
		m_list.InsertItem(i, _T(""));//触发重绘控件的代码
		m_list.SetItemInfo(i, wxData);
	}

	
}


void CDrowListControlitemDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	CString SNNumberData;
	CString photoPathData;

	CFile file(_T("array.txt"), CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store);
	int dataCount = 0;
	dataCount = 40;
	
	ar << dataCount;

	for (int i = 0; i < dataCount; i++)
	{
		ListData *model = new  ListData();
		SNNumberData.Format(_T("DY0900010%d"), i);
		model->m_equmentData = SNNumberData;
		photoPathData.Format(_T("C:\\Users\\SHICHUAN\\Desktop\\桌面文件\\lili\\%d.jpg"), i);//照片的路径
		model->m_photoPathData = photoPathData;
		ar << SNNumberData << photoPathData;//序列化
	}
	  
	ar.Close();
	file.Close();
	MessageBox(_T("串行化成功"));

}


void CDrowListControlitemDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	CFile flie(_T("array.txt"), CFile::modeRead);
	CArchive ar(&flie, CArchive::load);
	CArray<ModelStruct, ModelStruct&> modelArray;
	int dataCount = 40;


	ar >> dataCount;

	for (int i = 0; i < 40; i++)
	{
		ModelStruct wxData;
		ar >> wxData.SNNumber >> wxData.photoPath;
		modelArray.Add(wxData);	
	}


	for (int i = 0; i < dataCount; i++)
	{
		m_list.InsertItem(0, _T(""));//触发重绘控件的代码
		m_list.SetItemInfo(0, modelArray[i]);
	}




}
