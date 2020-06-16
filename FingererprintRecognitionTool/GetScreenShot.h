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

	// 获取屏幕截图
	bool HbitmaoToMat(HBITMAP& hBmp, Mat& _mat);
	int Screen(int& iwidth, int& iheight, Mat& _mat);

	// 获取每个指纹的图
	int GetFingPrint(Mat _mat, Mat* mat_target, Rect* rect_target, int iLenth);
	
};

