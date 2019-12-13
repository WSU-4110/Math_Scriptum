#include <QtTest>
#include <QtTest/QtTest>
#include <QLine>
#include <math.h>
///define PI using C++ math library
#define M_PI  3.14159265358979323846

// add necessary includes here

class test : public QObject
{
    Q_OBJECT

public:
    test();
    ~test();

private slots:
    void test_Shape10();
    void test_Shape12();
    void test_Shape11();
    void testHex();
    void testLines();
	void test_case1();
    void test_case2();
    void test_case3();
    void test_case4();
    void test_case5();
	void SaveImage();
    void SaveImage_data();
    void SelectSaveFile();
    void SelectSaveFile_data();
    void SaveProgress();
    void SaveProgress_data();
    void CreateSaveState();
    void CreateSaveState_data();
    void selectSaveState();
    void selectSaveState_data();

};

test::test()
{

}

test::~test()
{

}

void test::test_Shape10()
{

    float t = 0;
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x = 6 * cos_t * cos_t * cos_t * cos_t;
    float y = 6 * sin_t * sin_t * sin_t * sin_t;
    QVERIFY2(cos_t > sin_t, "SINE is smaller then COSINE");
}

void test::test_Shape11()
{
    float t = 0;
    float vertex = 15;
    float secondVertex = 4;

    float x = vertex * cos (t) - secondVertex * cos (vertex / secondVertex * t);
    float y = vertex * sin (t) - secondVertex * sin (vertex / secondVertex * t);
    QCOMPARE(1, cos(t));


}

void test::test_Shape12()
{
    float t = 0.8490238;
    float t1 = 9;
    float t2 = 4;
    float t3 = 9;

    float x = (t1 - t2) * cos (t) + t3 * cos (t * ((t1 - t2) / t2));
    float y = (t1 - t2) * sin (t) - t3 * sin (t * ((t1 - t2) / t2));
    QTRY_VERIFY2_WITH_TIMEOUT(x > sin(t),"SHOULD BE UNDER 4MS",5);

}

void test::testLines()
{
    float t = 1;
    float PI = 3.14159265358979323846;
    float t1 = 19;
    float t2 = 5;
    float t3 = 19;

    float x = (t1 - t2) * cos (t) + t3 * cos (t * ((t1 - t2) / t2));
    float y = (t1 - t2) * sin (t) - t3 * sin (t * ((t1 - t2) / t2));

   QTRY_VERIFY2(PI < x || PI < y, "PI SHOULD BE SMALLER THEN X AN Y IN TERMS OF SIN AND COS");

}

void test::testHex()
{
    float t = 1;
    float basicEdge = 0.841471;
    float edge1 = 2;
    float edge2 = 1;
    QPointF(edge1*cos(t), edge2*sin(t));
    QTRY_COMPARE_WITH_TIMEOUT(basicEdge, (edge1*cos(t), edge2*sin(t)), 4);

}

void test::test_case1()
{
    float t= 0;
    float slope = -1.0;
    float yIntercept = 0;
    float x = t;
    float y = slope * x + yIntercept;
    QCOMPARE(x,y);
}

void test::test_case2()
{
    float t = 5;
    float x = t;
    float y = x * x;
    QCOMPARE(pow(x,2),y);

}
void test::test_case3()
{
    float t = 9;
    float x = t;
    float y = sqrt(x);
    QCOMPARE(3,y);
}

void test::test_case4()
{
    float t = 10;
    float x = t;
    float y = 1/x;

    QVERIFY(y == 1/x);
}

void test::test_case5()
{
float t = 7;
float x = t;
    QVERIFY(t == x);
}

void test::SaveImage()
{
    // The SaveImage button does the following (in * comments).

    // This emulates the inputs/file location that result in a pass, program will not continue without a file path.
    QFETCH(QString, input);
    /*
    /// A QString object called path is where the sheape will be saved to as a png file.
    QString path = QFileDialog::getSaveFileName(this, tr("Save as image"), "/home/jana/shapes/untitled.png", tr("PNG (*.png)"));
    if (path.isEmpty())
    {
        /// If path is empty then this message will warn the user.
        QMessageBox::warning(this, "Warning!","No file location (path) created! Shape will not be saved!");
        return;
    }
    */

    // The following is what will happen, image will be saved or nothing will happen (if no file path).
    QFETCH(QString, result);
    /*
    /// A QImage object called img is referencing the shape area.
    QImage img(this->ui->Shapearea->size(), QImage::Format_ARGB32);
    /// Getting the content/image that is to be saved.
    QPainter painter(&img);
    this->render(&painter);
    /// Save the png image at the location (path) selected previously.
    img.save(path);
     */


    QCOMPARE(input, result);
}

void test::SaveImage_data()
{
    QTest::addColumn<QString>("input");
    QTest::addColumn<QString>("result");

    // The user does not choose a file location resulting in no file path and there fore no image saved.
    QTest::newRow("No Image Saved") << "" << "";

    // The user chose a valid file location.
    QTest::newRow("Image saved") << "D:\\Desktop_Files\\untitled.png" << "D:\\Desktop_Files\\untitled.png";
}

void test::SelectSaveFile()
{
    // The SelectSaveFile button does the following (in * comments).

    // This emulates the inputs/file location that result in a pass/don't crash the system.
    /*
    /// The user selects the location (path) of the save file to open.
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Save File"), "/home", tr("Text (*.txt)"));
    /// SaveFile is a QFile object to check if a save file has been created by the user.
    QFile SaveFile(fileName);
    */

    // The following is an if statement to check to see if the file opens or not.
    // Should the file not open, then a message will warn the user of it.
    // This couldn't be tested in Qt Test (If it could, I didn't find it after researching).
    /*
    if (!SaveFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        /// If no save file is selected, then this a message will pop up to warn the user.
        QMessageBox::warning(this, "Warning!","No save file has been SELECTED! Until a save file is created or selected, nothing will be saved!");
        return;
    }
    */

    // File's location is set to the global variable filePath, if it exists (otherwise no change).
    /*
    /// The file path (location) of the save file is set.
    filePath = fileName;
    */

    // This emulates the file's content that is read by the program.
    /*
    /// A QTextStream object called out is used to read from the selected save file.
    QTextStream in(&SaveFile);
    /// A QString object called FileContent is used to hold all the lines that were read from the file.
    QString FileContent = in.readAll();
    */

    // There are 2 possible passes, which are no content and some content in the file.
    /*
    /// Clear the Graphical Notepad in the main window
    ui->textEdit->clear();
    /// Add all the information from the selected file to Graphical Notepad in the main window
    ui->textEdit->setPlainText(FileContent);
    /// SaveFile is closed.
    SaveFile.close();
     */

    QFETCH(QString, input);
    QFETCH(QString, result);
    QCOMPARE(input, result);
}

void test::SelectSaveFile_data()
{
    QTest::addColumn<QString>("input");
    QTest::addColumn<QString>("result");

    // The user does not choose a file location resulting in no file path and therefore no save file.
    QTest::newRow("Empty File Location") << "" << "";

    // The user chose a valid file location.
    QTest::newRow("Save File Selected") << "D:\\Desktop_Files\\untitled.txt" << "D:\\Desktop_Files\\untitled.txt";

    // The save file has nothing in it.
    QTest::newRow("Empty File") << "" << "";

    // The save file has some content.
    QTest::newRow("NOT Empty File") << "Hello.\nThis is to show that the file isn't empty."
                                    << "Hello.\nThis is to show that the file isn't empty.";
}

void test::SaveProgress()
{
    // The SaveProgress button does the following (in * comments).

    // This emulates the inputs/file location that result in a pass, program will not continue without a file path.
    /*
    /// Get the file path (location) of the save file.
    QString filename = filePath;
    /// If no save file is set, then this message will warn the user.
    if (filename.isEmpty())
    {
        QMessageBox::warning(this, "Warning!","No save file has been set! Until a save file is created OR selected, nothing can be saved!");
        return;
    }
    */

    // File is set to the global variable filePath's location, if it exists (otherwise no change).
    /*
    /// SaveFile is a QFile object to check if a save file has been created by the user.
    QFile SaveFile(filename);
    */

    // The following is an if statement to check to see if the file opens or not.
    // Should the file not open, then a message will warn the user of it.
    // This couldn't be tested in Qt Test (If it could, I didn't find it after researching).
    /*
    /// Open the file
    if ( !SaveFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        /// If the file failed to open, then this message will warn the user.
        QMessageBox::warning(this, "Warning!","Save file failed to open! Select or Create a save file and then try again!");
        return;
    }
    */

    // This emulates the Graphical Notepad area's content that is read by the program.
    /*
    /// Clear the save file.
    SaveFile.resize(0);
    /// A QTextStream object called out is used to write to the selected save file.
    QTextStream out(&SaveFile);
    /// Everything in the Graphical notepad area is saved as plain text.
    out << ui->textEdit->toPlainText() << "\n";
    */

    // The two possible passes, which are no content and some content in the file.
    /*
    /// SaveFile is closed.
    SaveFile.close();
     */

    QFETCH(QString, input);
    QFETCH(QString, result);
    QCOMPARE(input, result);
}

void test::SaveProgress_data()
{
    QTest::addColumn<QString>("input");
    QTest::addColumn<QString>("result");

    // The user does not have a save file location resulting in no file path and therefore no progress saved.
    QTest::newRow("Empty Save File Location") << "" << "";

    // The user has a valid save file location.
    QTest::newRow("Save File Found") << "D:\\Desktop_Files\\untitled.txt" << "D:\\Desktop_Files\\untitled.txt";

    // The Graphical Notepad area has nothing in it.
    QTest::newRow("Empty NoteArea") << "" << "";

    // The Graphical Notepad area has some content.
    QTest::newRow("NOT Empty NoteArea") << "Hello.\nThis is to show that the NoteArea isn't empty."
                                        << "Hello.\nThis is to show that the NoteArea isn't empty.";
}

void test::CreateSaveState()
{
    // The CreateSaveState button does the following (in * comments).

    // This emulates the inputs/file location that result in a pass/don't crash the system.
    /*
    /// The location (path) of the state file is set.
    QString fileName = QFileDialog::getSaveFileName(this, tr("Create Save State"), "/home/jana/untitled.txt", tr("Text (*.txt)"));
    */

    // File is created if file's location is set, otherwise no change.
    /*
    /// StateFile is a QFile object to check if a state file has been created by the user.
    QFile StateFile(fileName);
    */

    // The following is an if statement to check to see if the file opens or not.
    // Should the file not open, then a message will warn the user of it.
    // This couldn't be tested in Qt Test (If it could, I didn't find it after researching).
    /*
    if (!StateFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        /// If no state file is create, then this a message will pop up to warn the user.
        QMessageBox::warning(this, "Warning!","No state file has been CREATED! Until a state file is created or selected, nothing will be saved!");
        return;
    }
    */

    // This emulates the possible inputs.
    /*
    /// Clear the state file just in case something is there (replaced file).
    StateFile.resize(0);
    /// A QTextStream object called out is used to write to the selected state file.
    QTextStream out(&StateFile);
    /// Record/write the state of shape area
    out << this->ui->Shapearea->shape() << "\n";
    out << this->ui->Shapearea->scale() << "\n";
    out << this->ui->Shapearea->length() << "\n";
    out << this->ui->Shapearea->step_counter() << "\n";
    /// Record/write the state of the save file
    out << filePath << "\n";
     */

    // There are possible 3 passes, which are default, custom without save file, and custom save state.
    /*
    /// StateFile is closed.
    StateFile.close();
    */

    QFETCH(QString, input);
    QFETCH(QString, result);
    QCOMPARE(input, result);
}

void test::CreateSaveState_data()
{
    QTest::addColumn<QString>("input");
    QTest::addColumn<QString>("result");

    // The user does not choose a file location resulting in no file path and therefore no save state file.
    QTest::newRow("Empty File Location") << "" << "";

    // The user chose a valid file location.
    QTest::newRow("Save State Created") << "D:\\Desktop_Files\\untitledSaveState.txt" << "D:\\Desktop_Files\\untitledSaveState.txt";

    // Default state file.
    QTest::newRow("Default State File") << "1\n99.99\n6.28\n255\n\n" << "1\n99.99\n6.28\n255\n\n";

    // The user creates a custom state file that does not have a save file.
    QTest::newRow("State File WITHOUT Save File") << "ShapeNumber\nScaleNumber\nLengthNumber\nStepNumber\n\n"
                                                  << "ShapeNumber\nScaleNumber\nLengthNumber\nStepNumber\n\n";

    // The preferred use of state file where the both the custom shape (and it's attributes) and save file location is stored.
    QTest::newRow("Optimal State File") << "ShapeNumber\nScaleNumber\nLengthNumber\nStepNumber\nFileLocation\n"
                                        << "ShapeNumber\nScaleNumber\nLengthNumber\nStepNumber\nFileLocation\n";
}

void test::selectSaveState()
{
    // The SelectSaveState button does the following (in * comments).

    // This emulates the inputs/file location that result in a pass/don't crash the system.
    /*
    /// The user selects the location (path) of the state file to open.
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open State File"), "/home", tr("Text (*.txt)"));
    */

    // File is created if file's location is set, otherwise no change.
    /*
    /// StateFile is a QFile object to check if a state file has been created by the user.
    QFile StateFile(fileName);
    */

    // The following is an if statement to check to see if the file opens or not.
    // Should the file not open, then a message will warn the user of it.
    // This couldn't be tested in Qt Test (If it could, I didn't find it after researching).
    /*
    if (!StateFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        /// If no state file is selected, then this a message will pop up to warn the user.
        QMessageBox::warning(this, "Warning!","No state file has been SELECTED!");
        return;
    }
    */

    // This emulates the possible inputs.
    /*
    /// A QTextStream object called out is used to read from the selected state file.
    QTextStream in(&StateFile);
    /// A QString object called FileContent is used to hold all the lines that were read from the file.
    QString line = in.readLine();
    this->ui->Shapearea->setShapeFromSaveState(line.toInt());
    line = in.readLine();
    this->ui->Shapearea->set_scale_size(line.toFloat());
    line = in.readLine();
    this->ui->Shapearea->set_length_of_shape(line.toFloat());
    line = in.readLine();
    this->ui->Shapearea->set_step_counter(line.toInt());
    line = in.readLine();
    filePath = line;
    */

    // The possible  passes, which are default, custom without save file, and custom save state.
    /*
    /// StateFile is closed.
    StateFile.close();
    this->ui->Shapearea->repaint();
    update_UserInterface();
    */

    // The following is an if statement to check to see if the file opens or not.
    // Should the file not open, then a message will warn the user of it.
    // This couldn't be tested in Qt Test (If it could, I didn't find it after researching).
    /*
    QFile copyFile(filePath);
    if (!copyFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        ///Opens a message box stating that the selected file did not open properly and will return from function
        QMessageBox::warning(this, "Warning!","File not open!");
        return;
    }
    */

    // This emulates the file's content that is read by the program.
    /*
    /// A QTextStream object called out is used to read from the selected state file.
    QTextStream text(&copyFile);
    /// A QString object called FileContent is used to hold all the lines that were read from the file.
    QString FileContent = text.readAll();
    */

    // There are 2 possible passes, which are no content and some content in the file.
    /*
    /// Clear the Graphical Notepad in the main window
    ui->textEdit->clear();
    /// Add all the information from the selected file to Graphical Notepad in the main window
    ui->textEdit->setPlainText(FileContent);
     */

    QFETCH(QString, input);
    QFETCH(QString, result);
    QCOMPARE(input, result);
}

void test::selectSaveState_data()
{
    QTest::addColumn<QString>("input");
    QTest::addColumn<QString>("result");

    // The user does not choose a file location resulting in no file path and therefore no save state file.
    QTest::newRow("Empty File Location") << "" << "";

    // The user chose a valid file location.
    QTest::newRow("Save State Selected") << "D:\\Desktop_Files\\untitledSaveState.txt" << "D:\\Desktop_Files\\untitledSaveState.txt";

    // The sate file has the Default contents.
    QTest::newRow("Default State File") << "1\n99.99\n6.28\n255\n\n" << "1\n99.99\n6.28\n255\n\n";

    // The state does not have a save file, but does have the other contents (includes possible mix of default contents).
    QTest::newRow("State File WITHOUT Save File") << "ShapeNumber\nScaleNumber\nLengthNumber\nStepNumber\n\n"
                                                  << "ShapeNumber\nScaleNumber\nLengthNumber\nStepNumber\n\n";

    // The state file has a save file and the other contents (includes possible mix of default contents).
    QTest::newRow("Optimal State File") << "ShapeNumber\nScaleNumber\nLengthNumber\nStepNumber\nFileLocation\n"
                                        << "ShapeNumber\nScaleNumber\nLengthNumber\nStepNumber\nFileLocation\n";

    // The save file has nothing in it.
    QTest::newRow("Empty File") << "" << "";

    // The save file has some content.
    QTest::newRow("NOT Empty File") << "Hello.\nThis is to show that the file isn't empty."
                                    << "Hello.\nThis is to show that the file isn't empty.";
}

QTEST_APPLESS_MAIN(test)

#include "tst_test.moc"
