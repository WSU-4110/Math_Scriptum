#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QColor>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QListWidget>
#include "shapewindow.h"
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
//void MainWindow::on_spinScale_valueChanged(double scaler)
//{

//}
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
    /// The user selects the location (path) of the save file to open.
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Save File"), "/home", tr("Text (*.txt)"));

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

    /// A QTextStream object called out is used to read from the selected save file.
    QTextStream in(&SaveFile);

    /// A QString object called FileContent is used to hold all the lines that were read from the file.
    QString FileContent = in.readAll();

    /// Clear the Graphical Notepad in the main window
    ui->textEdit->clear();

    /// Add all the information from the selected file to Graphical Notepad in the main window
    ui->textEdit->setPlainText(FileContent);

    /// SaveFile is closed.
    SaveFile.close();
}

void MainWindow::on_createSaveFileButton_clicked()
{
    /// The location (path) of the save file is set.
    QString fileName = QFileDialog::getSaveFileName(this, tr("Create Save File"), "/home/jana/untitled.txt", tr("Text (*.txt)"));

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
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file", "/home", tr("Text (*.txt)"));

    ///Creates a QFile object with the file name parameter
    QFile file(fileName);
    filePath = fileName;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        ///Opens a message box stating that the selected file did not open properly and will return from function
        QMessageBox::warning(this, "Warning!","File not open!");
        return;
    }

    ///Creates an object for the text read from the selected file
    QTextStream in(&file);

    ///String object to hold the text read from the QTextStream object
    QString inText = in.readAll();

    if (inText.isNull())
    {
        /// If the text file is empty, then this a message will pop up to warn the user.
        QMessageBox::warning(this, "Warning!","The file is empty!");
    }
    else
    {
        ///points the QString object to the graphical notepad area in the main window
        ui->textEdit->setText(inText);
    }

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

    /// Clear the save file.
    SaveFile.resize(0);

    /// A QTextStream object called out is used to write to the selected save file.
    QTextStream out(&SaveFile);

    /// Everything in the Graphical notepad area is saved as plain text.
    out << ui->textEdit->toPlainText() << "\n";

    /// SaveFile is closed.
    SaveFile.close();
}

void MainWindow::on_saveImage_clicked()
{
    /// A QString object called path is where the sheape will be saved to as a png file.
    QString path = QFileDialog::getSaveFileName(this, tr("Save as image"), "/home/jana/shapes/untitled.png", tr("PNG (*.png)"));

    if (path.isEmpty())
    {
        /// If path is empty then this message will warn the user.
        QMessageBox::warning(this, "Warning!","No save file location (path) created! Shape will not be saved!");
        return;
    }

    /// A QImage object called img is referencing the shape area.
    QImage img(this->ui->Shapearea->size(), QImage::Format_ARGB32);

    /// Getting the content/image that is to be saved.
    QPainter painter(&img);
    this->render(&painter);

    /// Save the png image at the location (path) selected previously.
    img.save(path);
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
    this->ui->Shapearea->set_up_Shape(ShapeArea::Line);
    this->ui->Shapearea->repaint();
    update_UserInterface();
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

void MainWindow::on_lineButton_clicked()
{
    this->ui->equationsArea->set_up_Graph(EquationsArea::Line);
   this->ui->equationsArea->repaint();
   update_UserInterface();
}

void MainWindow::on_parabolaButton_clicked()
{
    this->ui->equationsArea->set_up_Graph(EquationsArea::Parabola);
   this->ui->equationsArea->repaint();
   update_UserInterface();
}

void MainWindow::on_sqrtButton_clicked()
{
    this->ui->equationsArea->set_up_Graph(EquationsArea::Sqrt);
   this->ui->equationsArea->repaint();
   update_UserInterface();
}

void MainWindow::on_xRecipButton_clicked()
{
    this->ui->equationsArea->set_up_Graph(EquationsArea::XReciprical);
   this->ui->equationsArea->repaint();
   update_UserInterface();
}


void MainWindow::on_background_color_button_clicked()
{
    QColor c = QColorDialog::getColor(ui->Shapearea->get_background_color(),this, "Choose a Color!");
    ui->Shapearea->set_color_of_window(c);

}

void MainWindow::on_line_color_button_clicked()
{
    QColor c = QColorDialog::getColor(ui->Shapearea->get_pixel_color(),this, "Choose a Color!");
    ui->Shapearea->set_pixel_color(c);

}



void MainWindow::on_shape10Button_clicked()
{
    this->ui->Shapearea->set_up_Shape(ShapeArea::shape10);
    this->ui->Shapearea->repaint();
    update_UserInterface();
}


void MainWindow::on_shape11Button_clicked()
{
    this->ui->Shapearea->set_up_Shape(ShapeArea::shape11);
    this->ui->Shapearea->repaint();
    update_UserInterface();
}

void MainWindow::on_shape12Button_clicked()
{
    this->ui->Shapearea->set_up_Shape(ShapeArea::shape12);
    this->ui->Shapearea->repaint();
    update_UserInterface();
}


void MainWindow::on_limitsButton_clicked()
{

    QImage img1("/Users/sishirbuddha/Desktop/Limits1.png");
    QPixmap pm = QPixmap::fromImage(img1);

    QImage img2("/Users/sishirbuddha/Desktop/Limits2.png");
    QPixmap pm2 = QPixmap::fromImage(img2);

    QMessageBox displayLimits;
    QMessageBox displayLimits2;

    displayLimits.setWindowTitle("Limits");
    displayLimits.setText("Limits Page One");
    displayLimits.setIconPixmap(pm);
    displayLimits.icon();
    displayLimits.exec();

    displayLimits2.setWindowTitle("Limits Page Two");
    displayLimits2.setText("Limits Page Two");
    displayLimits2.setIconPixmap(pm);
    displayLimits2.icon();
    displayLimits2.exec();

    return;
}

void MainWindow::on_derivativesButton_clicked()
{

    QImage img1("/Users/sishirbuddha/Desktop/Deriv1.png");
    QPixmap pm = QPixmap::fromImage(img1);

    QImage img2("/Users/sishirbuddha/Desktop/Deriv2.png");
    QPixmap pm2 = QPixmap::fromImage(img2);

    QImage img3("/Users/sishirbuddha/Desktop/Deriv3.png");
    QPixmap pm3 = QPixmap::fromImage(img3);

    QImage img4("/Users/sishirbuddha/Desktop/Deriv4.png");
    QPixmap pm4 = QPixmap::fromImage(img4);

    QMessageBox displayDerivatives;
    QMessageBox displayDerivatives2;
    QMessageBox displayDerivatives3;
    QMessageBox displayDerivatives4;


    displayDerivatives.setWindowTitle("Derivatives");
    displayDerivatives.setText("Derivatives Page One");
    displayDerivatives.setIconPixmap(pm);
    displayDerivatives.icon();
    displayDerivatives.exec();

    displayDerivatives2.setWindowTitle("Derivatives Page Two");
    displayDerivatives2.setText("Derivatives Page Two");
    displayDerivatives2.setIconPixmap(pm2);
    displayDerivatives2.icon();
    displayDerivatives2.exec();

    displayDerivatives3.setWindowTitle("Derivatives Page Three");
    displayDerivatives3.setText("Derivatives Page Three");
    displayDerivatives3.setIconPixmap(pm3);
    displayDerivatives3.icon();
    displayDerivatives3.exec();

    displayDerivatives4.setWindowTitle("Derivatives Page Four");
    displayDerivatives4.setText("Derivatives Page Four");
    displayDerivatives4.setIconPixmap(pm4);
    displayDerivatives4.icon();
    displayDerivatives4.exec();

    return;
}


void MainWindow::on_integralsButton_clicked()
{
    QImage img1("/Users/sishirbuddha/Desktop/Int1.png");
    QPixmap pm = QPixmap::fromImage(img1);

    QImage img2("/Users/sishirbuddha/Desktop/Int2.png");
    QPixmap pm2 = QPixmap::fromImage(img2);

    QImage img3("/Users/sishirbuddha/Desktop/Int3.png");
    QPixmap pm3 = QPixmap::fromImage(img3);

    QImage img4("/Users/sishirbuddha/Desktop/Int4.png");
    QPixmap pm4 = QPixmap::fromImage(img4);

    QImage img5("/Users/sishirbuddha/Desktop/Int5.png");
    QPixmap pm5 = QPixmap::fromImage(img5);

    QMessageBox displayIntegrals;
    QMessageBox displayIntegrals2;
    QMessageBox displayIntegrals3;
    QMessageBox displayIntegrals4;
    QMessageBox displayIntegrals5;

    displayIntegrals.setWindowTitle("Integrals");
    displayIntegrals.setText("Integrals Page One");
    displayIntegrals.setIconPixmap(pm);
    displayIntegrals.icon();
    displayIntegrals.exec();

    displayIntegrals2.setWindowTitle("Integrals Page Two");
    displayIntegrals2.setText("Integrals Page Two");
    displayIntegrals2.setIconPixmap(pm2);
    displayIntegrals2.icon();
    displayIntegrals2.exec();

    displayIntegrals3.setWindowTitle("Integrals Page Three");
    displayIntegrals3.setText("Integrals Page Three");
    displayIntegrals3.setIconPixmap(pm3);
    displayIntegrals3.icon();
    displayIntegrals3.exec();

    displayIntegrals4.setWindowTitle("Integrals Page Four");
    displayIntegrals4.setText("Integrals Page Four");
    displayIntegrals4.setIconPixmap(pm4);
    displayIntegrals4.icon();
    displayIntegrals4.exec();

    displayIntegrals5.setWindowTitle("Integrals Page Five");
    displayIntegrals5.setText("Integrals Page Five");
    displayIntegrals5.setIconPixmap(pm);
    displayIntegrals5.icon();
    displayIntegrals5.exec();

    return;
}


void MainWindow::on_pushButton_clicked()
{
    shapewindow = new ShapeWindow(this);
    shapewindow->show();
}
