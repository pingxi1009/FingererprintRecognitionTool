#include "FingererprintRecognitionTool.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FingererprintRecognitionTool w;
    w.show();
    return a.exec();
}
