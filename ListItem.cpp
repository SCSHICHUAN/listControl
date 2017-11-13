// ListItem.cpp : 实现文件
//

#include "stdafx.h"
#include "DrowListControlitem.h"
#include "ListItem.h"
#include<gdiplus.h>
using namespace Gdiplus;


// CListItem

IMPLEMENT_DYNAMIC(CListItem, CListCtrl)

CListItem::CListItem()
{
	m_uItemHeight = 0;
}

//CListItem::~CListItem()
//{
//}


BEGIN_MESSAGE_MAP(CListItem, CListCtrl)
	ON_WM_MEASUREITEM()
	ON_WM_MEASUREITEM_REFLECT()//设置行高的消息
END_MESSAGE_MAP()

int i = 0;

// CListItem 消息处理程序
// 结构为需要自绘的控件或者菜单项提供了必要的信息 "LPDRAWITEMSTRUCT"                   
void CListItem::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	

	ASSERT(lpDrawItemStruct->CtlType == ODT_LISTVIEW);//断言是listView
	
  
	//"tagDRAWITEMSTRUCT"应该是设置data的结构体https://msdn.microsoft.com/zh-cn/library/92fhtw0f.aspx
	ModelFromserver *S_model = (ModelFromserver *)lpDrawItemStruct->itemData;


	
	CDC dc;
	//它的作用是：关联windows的资源句柄和c++对象，窗口是资源，
	//绘图设备也是资源，所以它们的类中会有这个函数关联windows的资源句柄和c++对象
	dc.Attach(lpDrawItemStruct->hDC);


	//当item选择状态发生改变“"ODA_SELECT"”，“ODS_SELECTED”：如果项的状态为选中
	if ((lpDrawItemStruct->itemAction | ODA_SELECT) && (lpDrawItemStruct->itemState & ODS_SELECTED))
	{
		//选中item时的颜色
		//dc.SetTextColor(RGB(0,255, 255));
		dc.FillSolidRect(&lpDrawItemStruct->rcItem, RGB(181, 230, 255));//在一个矩形框里作色
	}
	else
	{   //没有选中item的颜色
		//dc.SetTextColor(RGB(100, 100, 100));
		dc.FillSolidRect(&lpDrawItemStruct->rcItem, RGB(50, 100, 50));
	}

	CBrush brush(RGB(255, 0, 0));
	dc.FrameRect(&lpDrawItemStruct->rcItem, &brush);//item画边框



	if (1)
	{
		
		CRect rect = &lpDrawItemStruct->rcItem;
		//CString str;
		//str.Format(_T("DY000010%d"), rect.top);


		CFont font;
		font.CreatePointFont(130, _T("微软雅黑"));
		dc.SelectObject(&font);

		CRect rectItem(lpDrawItemStruct->rcItem);
		//rectItem.left += 100*2+40;
		//rectItem.bottom -= 20;
		dc.SetTextColor(RGB(255, 255, 255));

		

		dc.DrawText(S_model->device, &rectItem, DT_VCENTER | DT_SINGLELINE);//DT_SINGLELINE:垂直对其
		rectItem.bottom -= 200;
		rectItem.top -= 100;
		font.DeleteObject();

		font.CreatePointFont(100, _T("宋体"));
		dc.SelectObject(&font);
		dc.SetTextColor(RGB(127, 127, 127));
		//dc.DrawText(pwxCont->strNickName, &rectItem, DT_VCENTER | DT_SINGLELINE);
		font.DeleteObject();
	}
	else if(0)
	{
		CRect rcItem(lpDrawItemStruct->rcItem);
		rcItem.left += 45;
		CFont font;
		font.CreatePointFont(130, _T("微软雅黑"));
		dc.SelectObject(&font);
		dc.SetTextColor(RGB(0, 0, 0));
	//	dc.DrawText(pwxCont->strNickName, &rcItem, DT_VCENTER | DT_SINGLELINE);
		font.DeleteObject();
	}


	
	
	//显示头像
	if (1)
	{
		Graphics g(this->m_hWnd);
		Image *m_image  = Image::FromFile(S_model->photoPath);
		
		CRect rcItem(lpDrawItemStruct->rcItem);
		rcItem.left += 10;
		rcItem.right = rcItem.left + 100*2;
		rcItem.bottom -= 10;
		rcItem.top += 10;

		//IStream *pstm;
		//::CreateStreamOnHGlobal(pwxCont->hHeadImg, FALSE, &pstm);
		//::Image *pImg = ::Image::FromStream(pstm);
		//Graphics graph(lpDrawItemStruct->hDC);
		g.DrawImage(m_image, rcItem.left, rcItem.top, rcItem.Width(), rcItem.Height());
		delete m_image;
		//pImg = NULL;
		//pstm->Release();
		//pstm = NULL;
	}

	
	dc.Detach();


}

//给对象赋值
BOOL CListItem::SetItemInfo(int nItem, ModelFromserver model)
{
	ModelFromserver *_model = new ModelFromserver;
	*_model = model;
	return SetItemData(nItem, (DWORD_PTR)(LPVOID)_model);
}

//获取对象
ModelFromserver CListItem::GetItemInfo(int nItem)
{
	ModelFromserver *model = (ModelFromserver *)GetItemData(nItem);
	return (*model);
}

//设置行高
void CListItem::SetItemHeight(UINT uHeight)
{
	m_uItemHeight = uHeight;

	CRect rcWin;
	GetWindowRect(&rcWin);
	WINDOWPOS wp;
	wp.hwnd = GetSafeHwnd();
	wp.cx = rcWin.Width();
	wp.cy = rcWin.Height();
	wp.flags = SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER;
	SendMessage(WM_WINDOWPOSCHANGED, 0, (LPARAM)&wp);
}

//设置行高
void CListItem::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{
	lpMeasureItemStruct->itemHeight = m_uItemHeight;
}

//删除对象
void CListItem::OnDeleteitem(NMHDR* pNMHDR, LRESULT* pResult)
{
	NM_LISTVIEW *pNMListView = (NM_LISTVIEW *)pNMHDR;
	// TODO: Add your control notification handler code here
	ModelStruct *model = (ModelStruct *)GetItemData(pNMListView->iItem);
	if (NULL != model)
	{
		delete model;
		model = NULL;
	}

	*pResult = 0;
}
