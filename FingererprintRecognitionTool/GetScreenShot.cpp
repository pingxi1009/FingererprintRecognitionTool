#include "GetScreenShot.h"


#define IPL_DEPTH_1U     1
#define IPL_DEPTH_8U     8

GetScreenShot::GetScreenShot()
{
}


GetScreenShot::~GetScreenShot()
{
}

// 获取屏幕截图
int GetScreenShot::Screen(int& iwidth, int& iheight, Mat& _mat)
{
	//创建画板
	HDC hScreen = CreateDC(TEXT("DISPLAY"), NULL, NULL, NULL);
	HDC	hCompDC = CreateCompatibleDC(hScreen);

	//取得屏幕的宽度和高度
	iwidth  = GetSystemMetrics(SM_CXSCREEN);
	iheight = GetSystemMetrics(SM_CYSCREEN);
	//创建Bitmap对象
	HBITMAP hBmp = CreateCompatibleBitmap(hScreen, iwidth, iheight);
	HBITMAP hOld = (HBITMAP)SelectObject(hCompDC, hBmp);
	BitBlt(hCompDC, 0, 0, iwidth, iheight, hScreen, 0, 0, SRCCOPY);
	SelectObject(hCompDC, hOld);

	HbitmaoToMat(hBmp, _mat);

	//释放对象
	DeleteDC(hScreen);
	DeleteDC(hCompDC);
	DeleteObject(hBmp);

	return 0;
}

bool GetScreenShot::HbitmaoToMat(HBITMAP& _hBmp, Mat& _mat)
{
	//BITMAP操作
	BITMAP bmp;
	GetObject(_hBmp, sizeof(BITMAP), &bmp);
	int nChannels = bmp.bmBitsPixel == 1 ? 1 : bmp.bmBitsPixel / 8;
	int depth = bmp.bmBitsPixel == 1 ? IPL_DEPTH_1U : IPL_DEPTH_8U;
	//mat操作
	Mat v_mat;
	v_mat.create(Size(bmp.bmWidth, bmp.bmHeight), CV_MAKETYPE(CV_8U, nChannels));
	GetBitmapBits(_hBmp, bmp.bmHeight*bmp.bmWidth*nChannels, v_mat.data);
	_mat = v_mat;
	return TRUE;
}

int GetScreenShot::GetFingPrint(Mat _mat, Mat* mat_target, Rect* rect_target, int iLenth)
{
	for (int i = 0 ; i < iLenth; i++)
	{
		mat_target[i] = _mat(rect_target[i]);
	}
	

	return 0;
}