
// DrowListControlitemDlg.h : ͷ�ļ�
//
#pragma once
#include "afxcmn.h"
#include"ListItem.h"




// CDrowListControlitemDlg �Ի���
class CDrowListControlitemDlg : public CDialogEx
{
// ����
public:
	CDrowListControlitemDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DROWLISTCONTROLITEM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	Image *m_image;
	
	CPtrArray m_Equment;//��structָ�����飬model����struct

	//����ʼ����Ƭ������ʾ
	Gdiplus::GdiplusStartupInput m_pGdipluStartupInput;
	ULONG_PTR m_pGdiToken;//��ʼ��GDI��


	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListItem m_list; //ע��Ҫ����ͷ�ļ�
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void F(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMHoverList3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickList3(NMHDR *pNMHDR, LRESULT *pResult);
public:
	void CDrowListControlitemDlg::DrowPicture(ModelStruct mode);
};
