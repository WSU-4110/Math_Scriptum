#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QListWidget>

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



void MainWindow::on_limitsButton_clicked()
{
    QMessageBox::information(this, "Limits", "Definition: \n\nLet f be a function defined on some open interval that contains the number a, except possibly at a itself. We say the limit of f(x) as x approaches a is L, and we write lim f(x) as x -> a = L if for every number epsilon > 0 there is a corresponding number theta > 0 such that |f(x)-L| < epsilon whenever 0 < |x-a| < delta \n\nLeft-Hand [or Right-Hand] Limit: \n\nLet f be a function defined on some open interval (b,a) [or (a,b)]. We say the left-hand [or right-hand] limit of f(x) as x approaches a is L, (or the limit of f(x) as x approaches a from the left [or right] is L) and we write lim x->a- f(x) = L[lim x->a+ f(x) = L] if for every number epsilon > 0 there is a corresponding number delta > 0 such that |f(x)-L| < epsilon whenever a-epsilon < x < a[a < x < a + epsilon] ");
    return;
}

void MainWindow::on_derivativesButton_clicked()
{
    QMessageBox::information(this, "Derivatives", "Definition of the derivative: \n\nThe derivative of f(x) with respect to x is the function f'(x) and is defined as, f'x = lim h->0 (f(x+h)-f(x))/h \n\nDefinition: \n\nA function f(x)  is called differentiable at x =a if f'(a) exists and f(x) is called differentiable on an interval if the derivative exists for each point in that interval. \n\nTheorem: \n\nIf f(x) is differentiable at x = a then f(x) is continuous at x = a");
    return;
}


void MainWindow::on_integralsButton_clicked()
{
    QMessageBox::information(this, "Integrals", "Definition of the definite integral: \n\nGiven a function f(x) that is continuous on the interval [a,b] we divide the interval into n subintervals of equal width, Δx, and from each interval choose a point, x sub i *. Then the definite integral of f(x) from a to b is ∫ a->b f(x)dx = lim n->∞ ∑ i=1 to n f(x sub i *) Δx \n\nProperties: \n\n1.) ∫ a->b f(x)dx = -∫ b->a f(x)dx We can interchange the limits on any definite integral, all that we need to do is tack a minus sign onto the integral when we do. \n\n2.) ∫ a->a f(x)dx = 0 If the upper and lower limits are the same then there is no work to do, the integral is zero. \n\n3.) ∫ a->b cf(x)dx = c ∫ a->b f(x)dx, where c is any number. So, as with limits, derivatives, and indefinite integrals we can factor out a constant. \n\n4.) ∫ a->b f(x)dx +/- g(x)dx = ∫ a->b f(x)dx +/- ∫ a->b g(x)dx. We can break up definite integrals across a sum or difference. \n\n5.) ∫ a->b f(x)dx = ∫ a->c f(x)dx + ∫ c->b f(x)dx where c is any number. This property is more important than we might realize at first. One of the main uses of this property is to tell us how we can integrate a function over the adjacent intervals, [a,c] and [c,b]. Note however that c doesn’t need to be between a and b. \n\n6.) ∫ a->b f(x)dx = ∫ a->b f(t)dt. The point of this property is to notice that as long as the function and limits are the same the variable of integration that we use in the definite integral won’t affect the answer.");


    return;

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
