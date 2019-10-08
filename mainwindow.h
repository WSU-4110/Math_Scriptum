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


   void on_CycloidButton_clicked();

   void on_pushButton_clicked();

   void on_selectSaveFileButton_clicked();

   void on_createSaveFileButton_clicked();

private:
    Ui::MainWindow *ui;
private:
    void update_UserInterface ();
};
#endif // MAINWINDOW_H
