#include "FingererprintRecognitionTool.h"
#include "QString"

FingererprintRecognitionTool::FingererprintRecognitionTool(int width, int height, QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	QString strWidth = QString::number(width, 10);
	QString strHeight = QString::number(height, 10);

	QString str1 = "width = " + strWidth;
	QString str2 = "height = " + strHeight;

	ui.label_width->setText(str1);
	ui.label_height->setText(str2);

	
}
