#include "FingererprintRecognitionTool.h"
#include <QtWidgets/QApplication>
#include "GetScreenShot.h"

int main(int argc, char *argv[])
{
	GetScreenShot S;
	int height = 0;
	int width  = 0;
	Mat mat, dst;
	S.Screen(width, height, mat);
	resize(mat, dst, Size(1200, 800), 0, 0);
	imshow("dst", dst);
	waitKey(0);

    //QApplication a(argc, argv);
    //FingererprintRecognitionTool w(width, height);


    //w.show();

	
    //return a.exec();
	return 0;
}
