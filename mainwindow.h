#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    ///slots for the buttons created in the user interface
private slots:
    void on_astroid_Button_clicked();
   void on_spinScale_valueChanged(double arg1);


private:
    Ui::MainWindow *ui;
private:
    void update_UserInterface ();
};
#endif // MAINWINDOW_H
