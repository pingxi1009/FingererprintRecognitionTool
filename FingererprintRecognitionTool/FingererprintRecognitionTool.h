#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_FingererprintRecognitionTool.h"

class FingererprintRecognitionTool : public QMainWindow
{
    Q_OBJECT

public:
    FingererprintRecognitionTool(int width, int height, QWidget *parent = Q_NULLPTR);

private:
    Ui::FingererprintRecognitionToolClass ui;
};
