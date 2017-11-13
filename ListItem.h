#pragma once
#include"Model.h"


#ifndef _LISTITEM_
#define _LISTLTEM_


#include<gdiplus.h>
using namespace Gdiplus;
// CListItem

class CListItem : public CListCtrl
{
	DECLARE_DYNAMIC(CListItem)

public:
	CListItem();
	// Attributes
public:

	void SetItemHeight(UINT uHeight);
	BOOL SetItemInfo(int nItem, ModelFromserver wxCont);
	ModelFromserver GetItemInfo(int nItem);
	// Operations
public:

	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
protected:
	UINT m_uItemHeight;
	

	//virtual ~CListItem();//��ΪDrowListControlitemDlg�Ѿ����岻Ҫ������������������Ӧ��Ҳû���鹹����

protected:
	//{{AFX_MSG(CWXList)
	afx_msg void OnDeleteitem(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	afx_msg void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	DECLARE_MESSAGE_MAP()
};

#endif
