#include <opencv.hpp>
#include <afx.h>
#include <iostream>

using namespace std;
using namespace cv;

class GetScreenShot
{
public:
	GetScreenShot();
	~GetScreenShot();

	// ��ȡ��Ļ��ͼ
	bool HbitmaoToMat(HBITMAP& hBmp, Mat& _mat);
	int Screen(int& iwidth, int& iheight, Mat& _mat);

	// ��ȡÿ��ָ�Ƶ�ͼ
	int GetFingPrint(Mat _mat, Mat* mat_target, Rect* rect_target, int iLenth);
	
};

