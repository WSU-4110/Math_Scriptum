#include "shapewindow.h"
#include "ui_shapewindow.h"
#include "shapearea.h"
#include "ShapeWindow.h"
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

void ShapeWindow::update_UserInterface()
{
    this->ui->sCount->setValue(this->ui->Shapearea->step_counter());
    this->ui->sScale->setValue(this->ui->Shapearea->scale());
    this->ui->sInterval->setValue(this->ui->Shapearea->length());
}

void ShapeWindow::on_sCount_valueChanged(int arg1)
{
    this->ui->Shapearea->set_step_counter(arg1);
}

void ShapeWindow::on_sInterval_valueChanged(double arg1)
{
    this->ui->Shapearea->set_length_of_shape(arg1);
}

void ShapeWindow::on_sScale_valueChanged(double arg1)
{
    this->ui->Shapearea->set_scale_size(arg1);
}


void ShapeWindow::on_shape12Button_clicked()
{
    this->ui->Shapearea->set_up_Shape(ShapeArea::shape12);
    this->ui->Shapearea->repaint();
    update_UserInterface();
}

void ShapeWindow::on_shape11Button_clicked()
{
    this->ui->Shapearea->set_up_Shape(ShapeArea::shape11);
    this->ui->Shapearea->repaint();
    update_UserInterface();
}

void ShapeWindow::on_shape10Button_clicked()
{
    this->ui->Shapearea->set_up_Shape(ShapeArea::shape10);
    this->ui->Shapearea->repaint();
    update_UserInterface();
}

void ShapeWindow::on_line_Button_clicked()
{
    this->ui->Shapearea->set_up_Shape(ShapeArea::Lines);
    this->ui->Shapearea->repaint();
    update_UserInterface();
}

void ShapeWindow::on_huyg_Button_clicked()
{
    this->ui->Shapearea->set_up_Shape(ShapeArea::Huygens);
    this->ui->Shapearea->repaint();
    update_UserInterface();
}

void ShapeWindow::on_invertedCircle_Button_clicked()
{
    this->ui->Shapearea->set_up_Shape(ShapeArea::Line);
    this->ui->Shapearea->repaint();
    update_UserInterface();
}

void ShapeWindow::on_hypo_Button_clicked()
{
    this->ui->Shapearea->set_up_Shape(ShapeArea::Hype);
    this->ui->Shapearea->repaint();
    update_UserInterface();
}

void ShapeWindow::on_hexagon_Button_clicked()
{
    this->ui->Shapearea->set_up_Shape(ShapeArea::hexagon);
        this->ui->Shapearea->repaint();
        update_UserInterface();
}

void ShapeWindow::on_ellipse_Button_clicked()
{
    this->ui->Shapearea->set_up_Shape(ShapeArea::Ellipse);
    this->ui->Shapearea->repaint();
    update_UserInterface();
}

void ShapeWindow::on_circle_Button_clicked()
{
    this->ui->Shapearea->set_up_Shape(ShapeArea::Circle);
    this->ui->Shapearea->repaint();
    update_UserInterface();
}

void ShapeWindow::on_astroid_Button_clicked()
{
    this->ui->Shapearea->set_up_Shape(ShapeArea::Astroid);
    this->ui->Shapearea->repaint();
    update_UserInterface();

}

void ShapeWindow::on_CycloidButton_clicked()
{
    ///set up the shape call it from the shapearea class
    this->ui->Shapearea->set_up_Shape(ShapeArea::Cycloid);
    ///repaint the area
    this->ui->Shapearea->repaint();
    ///display the new shape
    update_UserInterface();

}
