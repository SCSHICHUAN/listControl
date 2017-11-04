
// DrowListControlitemDlg.h : 头文件
//
#pragma once
#include "afxcmn.h"
#include"ListItem.h"




// CDrowListControlitemDlg 对话框
class CDrowListControlitemDlg : public CDialogEx
{
// 构造
public:
	CDrowListControlitemDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DROWLISTCONTROLITEM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	Image *m_image;
	
	CPtrArray m_Equment;//存struct指针数组，model接收struct

	//不初始化照片不会显示
	Gdiplus::GdiplusStartupInput m_pGdipluStartupInput;
	ULONG_PTR m_pGdiToken;//初始化GDI用


	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListItem m_list; //注意要引进头文件
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void F(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMHoverList3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickList3(NMHDR *pNMHDR, LRESULT *pResult);
public:
	void CDrowListControlitemDlg::DrowPicture(ModelStruct mode);
};
