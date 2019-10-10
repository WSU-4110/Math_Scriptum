#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

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
///when the user clicks the astroid button
void MainWindow::on_CycloidButton_clicked()
{
    ///set up the shape call it from the shapearea class
    this->ui->Shapearea->set_up_Shape(ShapeArea::Cycloid);
    ///repaint the area
    this->ui->Shapearea->repaint();
    ///display the new shape
    update_UserInterface();
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_selectSaveFileButton_clicked()
{
    // NOT DONE
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Save File"),
                                                     "/home",
                                                     tr("Document (*.docx)"));

}

void MainWindow::on_createSaveFileButton_clicked()
{
    // NOT DONE
    QString fileName = QFileDialog::getSaveFileName(this, tr("Create Save File"),
                                 "/home/jana/untitled.docx",
                                 tr("Document (*.docx)"));
}

void MainWindow::on_pasteFromFile_clicked()
{
        //this will be used to get multiple files to open sequencially
    //QStringList fileNames = QFileDialog::getOpenFileNames(this, "Open the file");

    ///Opens a dialog box to select a file to read into the NotePad area of the App
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");

    ///Creates a QFile object with the file name parameter
    QFile file(fileName);
    filePath = fileName;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        ///Opens a message box stating that the selected file did not open properly and will return from function
        QMessageBox::warning(this, "..","file not open");
        return;
    }

    ///Creates an object for the text read from the selected file
    QTextStream in(&file);

    ///String object to hold the text read from the QTextStream object
    QString inText = in.readAll();

    ///points the QString object to the graphical notepad area in the main window
    ui->textEdit->setText(inText);

    ///Closes the Qfile object that the text was read from
    file.close();
}
