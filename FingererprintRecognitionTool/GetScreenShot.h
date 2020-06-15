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

	// »ñÈ¡ÆÁÄ»½ØÍ¼
	bool HbitmaoToMat(HBITMAP& hBmp, Mat& _mat);
	int Screen(int& iwidth, int& iheight, Mat& _mat);
	
};

