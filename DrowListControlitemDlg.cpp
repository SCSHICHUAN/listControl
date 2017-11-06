
// DrowListControlitemDlg.cpp : ʵ���ļ�
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


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CDrowListControlitemDlg �Ի���



CDrowListControlitemDlg::CDrowListControlitemDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DROWLISTCONTROLITEM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDrowListControlitemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, m_list);//���㶨���listContr����stroryBoard
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
END_MESSAGE_MAP()


// CDrowListControlitemDlg ��Ϣ�������

BOOL CDrowListControlitemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	Gdiplus::GdiplusStartup(&m_pGdiToken, &m_pGdipluStartupInput, NULL);
	
	m_list.InsertColumn(0, _T("00000"), LVCFMT_FILL, 600);
	m_list.SetItemHeight(200);

	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDrowListControlitemDlg::OnPaint()
{
	

	
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
		m_list.InsertItem(i, _T(""));//�����ػ�ؼ��Ĵ���
		m_list.SetItemInfo(i, wxData);
	}
	
}

//ģ��������߱��ز������ݣ�������Ҫ��ʾ��listControl�����ֺ���Ƭ��
void CDrowListControlitemDlg::OnBnClickedButton2()
{
	
	
	CString SNNumberData;
	CString photoPathData;
	CString out = _T("1\n");

	for (int i = 0; i < 40; i++)
	{
		
		ModelStruct model;
		
		SNNumberData.Format(_T("DY0900010%d"), i);
		model.SNNumber = SNNumberData;

		photoPathData.Format(_T("C:\\Users\\SHICHUAN\\Desktop\\�����ļ�\\lili\\%d.jpg"), i);//��Ƭ��·��
		out += photoPathData;
		out += "\n";
		model.photoPath = photoPathData;

		m_Equment.Add(model);//�������ģ��model<struct>
		
	}

	out += "ddd56464646464dddd";
	

	//CString ת char 
	int len = out.GetLength();
	char *cstr = new char[len + 1];
	cstr[len] = 0;
	WideCharToMultiByte(CP_OEMCP, 0, out, -1, cstr, len, NULL, NULL);
	



	ofstream outfile;
	outfile.open("C:\\Users\\SHICHUAN\\Desktop\\12.txt");
	outfile << cstr << endl;
	delete cstr;
	outfile.close();

	
}


void CDrowListControlitemDlg::F(NMHDR *pNMHDR, LRESULT *pResult)
{
	// �˹���Ҫ�� Internet Explorer 5 ����߰汾��
	// ���� _WIN32_IE ������ >= 0x0500��
	LPNMHDFILTERBTNCLICK phdr = reinterpret_cast<LPNMHDFILTERBTNCLICK>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}



//listControl ĳһ����
void CDrowListControlitemDlg::OnNMClickList3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	ModelStruct model = m_list.GetItemInfo(pNMItemActivate->iItem);
	
	CFont font;
   font.CreatePointFont(150, L"΢���ź�");
   GetDlgItem(IDC_STATIC)->SetFont(&font);
	SetDlgItemText(IDC_STATIC, model.SNNumber);
	DrowPicture(model);
	*pResult = 0;
}

void CDrowListControlitemDlg::DrowPicture(ModelStruct mode)
{
	Graphics g(this->m_hWnd);
	Image *m_image = Image::FromFile(mode.photoPath);

	CRect rcItem(700,200, 1300,700);
	g.DrawImage(m_image, rcItem.left, rcItem.top, rcItem.Width(), rcItem.Height());
	delete m_image;
}




