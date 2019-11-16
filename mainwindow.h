#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QListWidgetItem>


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
   //void on_spinScale_valueChanged(double arg1);


   void on_CycloidButton_clicked();

   //void on_pushButton_clicked();

   void on_selectSaveFileButton_clicked();

   void on_createSaveFileButton_clicked();

   void on_pasteFromFile_clicked();

   void on_saveProgress_clicked();


   void on_circle_Button_clicked();



   void on_hexagon_Button_clicked();

   void on_ellipse_Button_clicked();


   void on_invertedCircle_Button_clicked();

   void on_hypo_Button_clicked();

   void on_huyg_Button_clicked();

   void on_line_Button_clicked();

   //void on_sScale_valueChanged(const QString &arg1);

   void on_sScale_valueChanged(double arg1);

   void on_sInterval_valueChanged(double arg1);

   void on_sCount_valueChanged(int arg1);

   void on_saveImage_clicked();


   void on_lineButton_clicked();

   void on_parabolaButton_clicked();

   void on_sqrtButton_clicked();

   void on_xRecipButton_clicked();

   void on_limitsButton_clicked();

   void on_derivativesButton_clicked();

   void on_integralsButton_clicked();


   void on_background_color_button_clicked();

   void on_line_color_button_clicked();

   //void on_pushButton_clicked();

   void on_shape10Button_clicked();

   void on_shape11Button_clicked();

   void on_shape12Button_clicked();

private:
    Ui::MainWindow *ui;
    QString filePath;
private:
    void update_UserInterface ();
};
#endif // MAINWINDOW_H
