#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     this->ui->spin_interval->setValue(this->ui->Shapearea->scale());


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::update_UserInterface()
{

}

///when the user clicks on the astroid button
void MainWindow::on_astroid_Button_clicked()
{
    ///change the background color for the shape area class
    /// adding a function to the change the color
    /// calling this ui to set shape area
    /// using ui to access shape area class
    /// use repaint to ensure that the window changes color when clicked ß

    this->ui->Shapearea->set_up_Shape(ShapeArea::Astroid);
    this->ui->Shapearea->repaint();
    update_UserInterface();

}

///function for when user clicks the spin value box to change values of the shape
void MainWindow::on_spinScale_valueChanged(double scaler)
{
    this->ui->Shapearea->set_scale_size(scaler);
}
