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
    /// The user selects the location (path) of the save file to open.
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Save File"),
                                                     "/home",
                                                     tr("Document (*.txt)"));

    /// SaveFile is a QFile object to check if a save file has been created by the user.
    QFile SaveFile(fileName);

    if (!SaveFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        /// If no save file is selected, then this a message will pop up to warn the user.
        QMessageBox::warning(this, "Warning!","No save file has been SELECTED! Until a save file is created or selected, nothing will be saved!");
        return;
    }

    /// The file path (location) of the save file is set.
    filePath = fileName;

    /// SaveFile is closed.
    SaveFile.close();
}

void MainWindow::on_createSaveFileButton_clicked()
{
    /// The location (path) of the save file is set.
    QString fileName = QFileDialog::getSaveFileName(this, tr("Create Save File"),
                                 "/home/jana/untitled.txt",
                                 tr("Document (*.txt)"));

    /// SaveFile is a QFile object to check if a save file has been created by the user.
    QFile SaveFile(fileName);

    if (!SaveFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        /// If no save file is create, then this a message will pop up to warn the user.
        QMessageBox::warning(this, "Warning!","No save file has been CREATED! Until a save file is created or selected, nothing will be saved!");
        return;
    }

    /// The file path (location) of the save file is set.
    filePath = fileName;

    /// SaveFile is closed.
    SaveFile.close();
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

void MainWindow::on_saveProgress_clicked()
{
    /// Get the file path (location) of the save file.
    QString filename = filePath;

    /// If no save file is set, then this message will warn the user.
    if (filename.isEmpty())
    {
        QMessageBox::warning(this, "Warning!","No save file has been set! Until a save file is created OR selected, nothing can be saved!");
        return;
    }

    /// SaveFile is a QFile object to check if a save file has been created by the user.
    QFile SaveFile(filename);

    /// Open the file
    if ( !SaveFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        /// If the file failed to open, then this message will warn the user.
        QMessageBox::warning(this, "Warning!","Save file failed to open! Select or Create a save file and then try again!");
        return;
    }

    /// out is a QTextStream object to write to the selected save file.
    QTextStream out(&SaveFile);

    /// Everything in the Graphical notepad area is saved as plain text.
    out << ui->textEdit->toPlainText() << "\n";

    /// SaveFile is closed.
    SaveFile.close();
}
