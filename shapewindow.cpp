#include "shapewindow.h"
#include "ui_shapewindow.h"

ShapeWindow::ShapeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShapeWindow)
{
    ui->setupUi(this);
}

ShapeWindow::~ShapeWindow()
{
    delete ui;
}
