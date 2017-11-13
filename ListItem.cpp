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


		CFont font;
		font.CreatePointFont(130, _T("΢���ź�"));
		dc.SelectObject(&font);

		CRect rectItem(lpDrawItemStruct->rcItem);
		rectItem.left += 10;
		rectItem.top -= 350;
		dc.SetTextColor(RGB(255, 255, 255));

		
		dc.DrawText(S_model->device, &rectItem, DT_VCENTER | DT_SINGLELINE);//DT_SINGLELINE:��ֱ����
		


		CFont font2;
		font2.CreatePointFont(80, _T("΢���ź�"));
		dc.SelectObject(&font2);


		CString str;
		str.Format(_T("id:%d"), S_model->id);
		CRect rectItem2(lpDrawItemStruct->rcItem);
		rectItem2.left += 10;
		rectItem2.top -= 350-60;
		dc.SetTextColor(RGB(255, 255, 255));
		dc.DrawText(str,&rectItem2, DT_VCENTER | DT_SINGLELINE);//DT_SINGLELINE:��ֱ����




		CFont font3;
		font3.CreatePointFont(80, _T("΢���ź�"));
		dc.SelectObject(&font3);


	
		str.Format(_T("token:%s"), S_model->token);
		CRect rectItem3(lpDrawItemStruct->rcItem);
		rectItem3.top -= 350 - 60;
		rectItem3.left += 110;
		dc.SetTextColor(RGB(255, 255, 255));
		dc.DrawText(str, &rectItem3, DT_VCENTER | DT_SINGLELINE);//DT_SINGLELINE:��ֱ����



		CFont font4;
		font4.CreatePointFont(80, _T("΢���ź�"));
		dc.SelectObject(&font4);



		str.Format(_T("address:%s"), S_model->address);
		CRect rectItem4(lpDrawItemStruct->rcItem);
		rectItem4.top -= 350 - 60;
		rectItem4.left += 110 +200;
		dc.SetTextColor(RGB(255, 255, 255));
		dc.DrawText(str, &rectItem4, DT_VCENTER | DT_SINGLELINE);//DT_SINGLELINE:��ֱ����


		CFont font5;
		font5.CreatePointFont(80, _T("΢���ź�"));
		dc.SelectObject(&font5);



		str.Format(_T("address:%s"), S_model->address2);
		CRect rectItem5(lpDrawItemStruct->rcItem);
		rectItem5.top -= 350 - 130;
		rectItem5.left += 10;
		dc.SetTextColor(RGB(255, 255, 255));
		dc.DrawText(str, &rectItem5, DT_VCENTER | DT_SINGLELINE);//DT_SINGLELINE:��ֱ����




		CFont font6;
		font6.CreatePointFont(80, _T("΢���ź�"));
		dc.SelectObject(&font6);



		str.Format(_T("latitude:%f"), S_model->latitude);
		CRect rectItem6(lpDrawItemStruct->rcItem);
		rectItem6.top -= 350 - 130-70;
		rectItem6.left += 10;
		dc.SetTextColor(RGB(255, 255, 255));
		dc.DrawText(str, &rectItem6, DT_VCENTER | DT_SINGLELINE);//DT_SINGLELINE:��ֱ����



		CFont font7;
		font7.CreatePointFont(80, _T("΢���ź�"));
		dc.SelectObject(&font7);



		str.Format(_T("longitude:%f"), S_model->longitude);
		CRect rectItem7(lpDrawItemStruct->rcItem);
		rectItem7.top -= 350 - 130 - 70;
		rectItem7.left +=210;
		dc.SetTextColor(RGB(255, 255, 255));
		dc.DrawText(str, &rectItem7, DT_VCENTER | DT_SINGLELINE);//DT_SINGLELINE:��ֱ����





		CFont font8;
		font8.CreatePointFont(80, _T("΢���ź�"));
		dc.SelectObject(&font8);



		str.Format(_T("description:%s"), S_model->description);
		CRect rectItem8(lpDrawItemStruct->rcItem);
		rectItem8.top -= 350 - 130 - 70-80;
		rectItem8.left += 10;
		dc.SetTextColor(RGB(255, 255, 255));
		dc.DrawText(str, &rectItem8, DT_VCENTER | DT_SINGLELINE);//DT_SINGLELINE:��ֱ����


		CFont font9;
		font9.CreatePointFont(80, _T("΢���ź�"));
		dc.SelectObject(&font9);



		str.Format(_T("refreshTime:%s"), S_model->refreshTime);
		CRect rectItem9(lpDrawItemStruct->rcItem);
		rectItem9.top -= 350 - 130 - 70 - 80-80;
		rectItem9.left += 10;
		dc.SetTextColor(RGB(255, 255, 255));
		dc.DrawText(str, &rectItem9, DT_VCENTER | DT_SINGLELINE);//DT_SINGLELINE:��ֱ����

	
		CFont font10;
		font10.CreatePointFont(80, _T("΢���ź�"));
		dc.SelectObject(&font10);



		str.Format(_T("isMaster:%d"), S_model->isMaster);
		CRect rectItem10(lpDrawItemStruct->rcItem);
		rectItem10.top -= 350 - 130 - 70 - 80 - 80-80;
		rectItem10.left += 10;
		dc.SetTextColor(RGB(255, 255, 255));
		dc.DrawText(str, &rectItem10, DT_VCENTER | DT_SINGLELINE);//DT_SINGLELINE:��ֱ����
		 


		CFont font11;
		font11.CreatePointFont(80, _T("΢���ź�"));
		dc.SelectObject(&font11);



		str.Format(_T("isOnline:%d"), S_model->isOnline);
		CRect rectItem11(lpDrawItemStruct->rcItem);
		rectItem11.top -= 350 - 130 - 70 - 80 - 80 - 80;
		rectItem11.left += 10 +130;
		dc.SetTextColor(RGB(255, 255, 255));
		dc.DrawText(str, &rectItem11, DT_VCENTER | DT_SINGLELINE);//DT_SINGLELINE:��ֱ����

		
		


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
