#include "FingererprintRecognitionTool.h"
#include <QtWidgets/QApplication>
#include "GetScreenShot.h"

const int ALL_FING_PRINT_NUM = 9;		// 所有需提取指纹个数
Rect rec_target[ALL_FING_PRINT_NUM] = {	// 指纹所在的区域矩形信息
	{ 1311, 209, 434, 672 },

	{ 631,  359, 160, 160 },
	{ 823,  359, 160, 160 },
	{ 631,  551, 160, 160 },
	{ 823,  551, 160, 160 },
	{ 631,  743, 160, 160 },
	{ 823,  743, 160, 160 },
	{ 631,  935, 160, 160 },
	{ 823,  935, 160, 160 },
};

int main(int argc, char *argv[])
{
	GetScreenShot S;
	int height = 0;
	int width  = 0;
	Mat mat, dst;
	S.Screen(width, height, mat);
	//resize(mat, dst, Size(1200, 800), 0, 0);
	imshow("mat", mat);
	ostringstream oss;
	//oss << "licenseIma" << ".jpg";
	//imwrite(oss.str(), mat);

	// 获取每个要指纹块
	Mat img = imread("target.jpg", 1);

	if(img.empty())
	{
		cout << "图像加载失败！" << endl;
		return -1;
	}

	Mat mat_target[ALL_FING_PRINT_NUM];
	S.GetFingPrint(img, mat_target, rec_target, ALL_FING_PRINT_NUM);
	
	// 打印出每个指纹快
	for (int i = 0 ; i < ALL_FING_PRINT_NUM ; i++)
	{
		ostringstream oss_target;
		oss_target << "target " << i << ".jpg";
		imwrite(oss_target.str(), mat_target[i]);
	}

	waitKey(0);

    QApplication a(argc, argv);
    FingererprintRecognitionTool w(width, height);


    w.show();

	
    return a.exec();
	//return 0;
}
