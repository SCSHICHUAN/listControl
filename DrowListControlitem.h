
// DrowListControlitem.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDrowListControlitemApp: 
// �йش����ʵ�֣������ DrowListControlitem.cpp
//

class CDrowListControlitemApp : public CWinApp
{
public:
	CDrowListControlitemApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDrowListControlitemApp theApp;
