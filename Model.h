
#ifndef _MODEL_
#define _MODEL_



typedef struct
{
	CString SNNumber;      // Ҫ��ʾ������
	CString photoPath;   //Ҫ��ʾ����Ƭ·��

}ModelStruct;


typedef struct
{
	int     count;
	int     total;
	int     page;
	int     size;
	CString mobile;

	int     id;
	CString device;
	CString token;
	CString address;
	CString address2;
	float   latitude;
	CString description;
	float   longitude;
	CString refreshTime;
	BOOL    isMaster;
	BOOL    isOnline;


	CString photoPath;


}ModelFromserver;




#endif

