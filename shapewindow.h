#ifndef SHAPEWINDOW_H
#define SHAPEWINDOW_H

#include <QDialog>

namespace Ui {
class ShapeWindow;
}

class ShapeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ShapeWindow(QWidget *parent = nullptr);
    ~ShapeWindow();

private slots:

    void on_sCount_valueChanged(int arg1);
    void on_sInterval_valueChanged(double arg1);
    void on_sScale_valueChanged(double arg1);

    void on_shape12Button_clicked();


    void on_shape11Button_clicked();

    void on_shape10Button_clicked();

    void on_line_Button_clicked();

    void on_huyg_Button_clicked();

    void on_invertedCircle_Button_clicked();

    void on_hypo_Button_clicked();

    void on_hexagon_Button_clicked();

    void on_ellipse_Button_clicked();

    void on_circle_Button_clicked();

    void on_astroid_Button_clicked();

    void on_CycloidButton_clicked();

private:
    void update_UserInterface ();

private:
    Ui::ShapeWindow *ui;
};

#endif // SHAPEWINDOW_H
