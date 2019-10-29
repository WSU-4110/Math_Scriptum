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
     this->ui->sInterval->setValue(this->ui->Shapearea->length());
     this->ui->sScale->setValue(this->ui->Shapearea->scale());

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::update_UserInterface()
{
    this->ui->sCount->setValue(this->ui->Shapearea->step_counter());
    this->ui->sScale->setValue(this->ui->Shapearea->scale());
    this->ui->sInterval->setValue(this->ui->Shapearea->length());
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



void MainWindow::on_selectSaveFileButton_clicked()
{
    // NOT DONE
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Save File"),
                                                     "/home",
                                                     tr("Document (*.docx)"));

    /// SaveFile is a QFile object to check if a save file has been created by the user.
    QFile SaveFile(fileName);
    if (!SaveFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        /// If no save file is selected, then this a message will pop up to warn the user.
        QMessageBox::warning(this, "Warning!","No save file has been SELECTED! Until a save file is created or selected, nothing will be saved!");
        return;
    }

    /// Savefile was not closed so the other functions should be able to write and read from it.
    SaveFile.open(QIODevice::WriteOnly);
}

void MainWindow::on_createSaveFileButton_clicked()
{
    // NOT DONE
    QString fileName = QFileDialog::getSaveFileName(this, tr("Create Save File"),
                                 "/home/jana/untitled.docx",
                                 tr("Document (*.docx)"));

    /// SaveFile is a QFile object to check if a save file has been created by the user.
    QFile SaveFile(fileName);
    if (!SaveFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        /// If no save file is create, then this a message will pop up to warn the user.
        QMessageBox::warning(this, "Warning!","No save file has been CREATED! Until a save file is created or selected, nothing will be saved!");
        return;
    }

    /// Savefile is open and not closed so the other functions should be able to write to it.
    SaveFile.open(QIODevice::WriteOnly);
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

}

void MainWindow::on_circle_Button_clicked()
{
    this->ui->Shapearea->set_up_Shape(ShapeArea::Circle);
    this->ui->Shapearea->repaint();
    update_UserInterface();
}



void MainWindow::on_hexagon_Button_clicked()
{
this->ui->Shapearea->set_up_Shape(ShapeArea::hexagon);
    this->ui->Shapearea->repaint();
    update_UserInterface();
}

void MainWindow::on_ellipse_Button_clicked()
{
    this->ui->Shapearea->set_up_Shape(ShapeArea::Ellipse);
    this->ui->Shapearea->repaint();
    update_UserInterface();
}


void MainWindow::on_invertedCircle_Button_clicked()
{

}

void MainWindow::on_hypo_Button_clicked()
{
    this->ui->Shapearea->set_up_Shape(ShapeArea::Hype);
    this->ui->Shapearea->repaint();
    update_UserInterface();
}

void MainWindow::on_huyg_Button_clicked()
{
    this->ui->Shapearea->set_up_Shape(ShapeArea::Huygens);
    this->ui->Shapearea->repaint();
    update_UserInterface();
}

void MainWindow::on_line_Button_clicked()
{
    this->ui->Shapearea->set_up_Shape(ShapeArea::Lines);
    this->ui->Shapearea->repaint();
    update_UserInterface();

}


void MainWindow::on_sScale_valueChanged(double scale)
{
   this->ui->Shapearea->set_scale_size(scale);
}

void MainWindow::on_sInterval_valueChanged(double scale)
{
    this->ui->Shapearea->set_length_of_shape(scale);
}

void MainWindow::on_sCount_valueChanged(int counter)
{
    this->ui->Shapearea->set_step_counter(counter);
}
