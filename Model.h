
#ifndef _MODEL_
#define _MODEL_



typedef struct
{
	CString SNNumber;      // 要显示的文字
	CString photoPath;   //要显示的照片路径

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

