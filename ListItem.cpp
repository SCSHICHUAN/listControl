// ListItem.cpp : ʵ���ļ�
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
	ON_WM_MEASUREITEM_REFLECT()//�����иߵ���Ϣ
END_MESSAGE_MAP()

int i = 0;

// CListItem ��Ϣ�������
// �ṹΪ��Ҫ�Ի�Ŀؼ����߲˵����ṩ�˱�Ҫ����Ϣ "LPDRAWITEMSTRUCT"                   
void CListItem::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	

	ASSERT(lpDrawItemStruct->CtlType == ODT_LISTVIEW);//������listView
	
  
	//"tagDRAWITEMSTRUCT"Ӧ��������data�Ľṹ��https://msdn.microsoft.com/zh-cn/library/92fhtw0f.aspx
	ModelFromserver *S_model = (ModelFromserver *)lpDrawItemStruct->itemData;


	
	CDC dc;
	//���������ǣ�����windows����Դ�����c++���󣬴�������Դ��
	//��ͼ�豸Ҳ����Դ���������ǵ����л��������������windows����Դ�����c++����
	dc.Attach(lpDrawItemStruct->hDC);


	//��itemѡ��״̬�����ı䡰"ODA_SELECT"������ODS_SELECTED����������״̬Ϊѡ��
	if ((lpDrawItemStruct->itemAction | ODA_SELECT) && (lpDrawItemStruct->itemState & ODS_SELECTED))
	{
		//ѡ��itemʱ����ɫ
		//dc.SetTextColor(RGB(0,255, 255));
		dc.FillSolidRect(&lpDrawItemStruct->rcItem, RGB(181, 230, 255));//��һ�����ο�����ɫ
	}
	else
	{   //û��ѡ��item����ɫ
		//dc.SetTextColor(RGB(100, 100, 100));
		dc.FillSolidRect(&lpDrawItemStruct->rcItem, RGB(50, 100, 50));
	}

	CBrush brush(RGB(255, 0, 0));
	dc.FrameRect(&lpDrawItemStruct->rcItem, &brush);//item���߿�



	if (1)
	{
		
		CRect rect = &lpDrawItemStruct->rcItem;
		//CString str;
		//str.Format(_T("DY000010%d"), rect.top);


		CFont font;
		font.CreatePointFont(130, _T("΢���ź�"));
		dc.SelectObject(&font);

		CRect rectItem(lpDrawItemStruct->rcItem);
		//rectItem.left += 100*2+40;
		//rectItem.bottom -= 20;
		dc.SetTextColor(RGB(255, 255, 255));

		

		dc.DrawText(S_model->device, &rectItem, DT_VCENTER | DT_SINGLELINE);//DT_SINGLELINE:��ֱ����
		rectItem.bottom -= 200;
		rectItem.top -= 100;
		font.DeleteObject();

		font.CreatePointFont(100, _T("����"));
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
		font.CreatePointFont(130, _T("΢���ź�"));
		dc.SelectObject(&font);
		dc.SetTextColor(RGB(0, 0, 0));
	//	dc.DrawText(pwxCont->strNickName, &rcItem, DT_VCENTER | DT_SINGLELINE);
		font.DeleteObject();
	}


	
	
	//��ʾͷ��
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

//������ֵ
BOOL CListItem::SetItemInfo(int nItem, ModelFromserver model)
{
	ModelFromserver *_model = new ModelFromserver;
	*_model = model;
	return SetItemData(nItem, (DWORD_PTR)(LPVOID)_model);
}

//��ȡ����
ModelFromserver CListItem::GetItemInfo(int nItem)
{
	ModelFromserver *model = (ModelFromserver *)GetItemData(nItem);
	return (*model);
}

//�����и�
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

//�����и�
void CListItem::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{
	lpMeasureItemStruct->itemHeight = m_uItemHeight;
}

//ɾ������
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
