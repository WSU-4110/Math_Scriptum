#include "shapewindow.h"
#include "ui_shapewindow.h"
#include "shapearea.h"
#include "shapewindow.h"
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
/*
 * The update user interface updates the shape with the new settings set by the user in real time (under 1 second load time)
 * use head pointer "this" to call the ui
 * call the setvalue which calls the shape area class and calls the stepper function
 * call the setvalue which calls the shape area class and calls the scaler function
 * call the setvalue which calls the shape area class and calls the length of shape function
 * */

void ShapeWindow::update_UserInterface()
{
    this->ui->sCount->setValue(this->ui->Shapearea->step_counter());
    this->ui->sScale->setValue(this->ui->Shapearea->scale());
    this->ui->sInterval->setValue(this->ui->Shapearea->length());
}
/*
 * The following 3 functions are the functoions for the parametric equation settings,
 * the scaler sets the scale of the shape
 * the counter increments the shape movement
 * the interval changes the shape depending on the user settings
 * */
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

/*
 * The following functions acheive the following
 * call the shape area class
 * call the set up shape which calls a shape declared in the shape area class
 * call the the repaint function which displays upodated shape that was just declared
 * call the update user interface function that updates the setting and displays the updated shape with the setting
 * */

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
    this->ui->Shapearea->set_up_Shape(ShapeArea::Cycloid);
    this->ui->Shapearea->repaint();
    update_UserInterface();

}
