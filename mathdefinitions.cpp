#include "mathdefinitions.h"
#include <QMessageBox>

mathDefinitions::mathDefinitions(QWidget *parent)
{
}
///locate resource file for the limits
/// display message box displaying the functions
/// set the title
/// set the size
/// set the pixMaps
/// show the final message box
void mathDefinitions::limit()
{
    ///the resource is within QT and not the PC
    QImage img1(":/resources/images/Limits1.png");
    QPixmap pm = QPixmap::fromImage(img1);
    QImage img2(":/resources/images/Limits2.png");
    QPixmap pm2 = QPixmap::fromImage(img2);

    ///open a message box
    QMessageBox displayLimits;
    QMessageBox displayLimits2;

    ///when the message box is opened, display the functions
    displayLimits.setWindowTitle("Limits");
    displayLimits.setText("Limits Page One");
    displayLimits.setIconPixmap(pm);
    displayLimits.icon();
    ///slightly larger since many functions are displayed
    displayLimits.setBaseSize(1000,1000);
    ///execute
    displayLimits.exec();
    displayLimits2.setWindowTitle("Limits Page Two");
    displayLimits2.setText("Limits Page Two");
    displayLimits2.setIconPixmap(pm2);
    displayLimits2.icon();
    displayLimits2.setBaseSize(1000,1000);
    displayLimits2.exec();
}
///locate resource file for the derivatives
/// display message box displaying the functions
/// set the title
/// set the size
/// set the pixMaps
/// show the final message box
void mathDefinitions::derivative()
{
    QImage img1(":/resources/images/Deriv1.png");
    QPixmap pm = QPixmap::fromImage(img1);
    pm = pm.scaled(800, 800, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QImage img2(":/resources/images/Deriv2.png");
    QPixmap pm2 = QPixmap::fromImage(img2);
    pm2 = pm2.scaled(800, 800, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QImage img3(":/resources/images/Deriv3.png");
    QPixmap pm3 = QPixmap::fromImage(img3);
    pm3 = pm3.scaled(800, 800, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QImage img4(":/resources/images/Deriv4.png");
    QPixmap pm4 = QPixmap::fromImage(img4);
    pm4 = pm4.scaled(800, 800, Qt::KeepAspectRatio, Qt::SmoothTransformation);



    QMessageBox displayDerivatives;
    QMessageBox displayDerivatives2;
    QMessageBox displayDerivatives3;
    QMessageBox displayDerivatives4;


    displayDerivatives.setWindowTitle("Derivatives");
    displayDerivatives.setText("Derivatives Page One");
    displayDerivatives.setIconPixmap(pm);
    displayDerivatives.icon();
    displayDerivatives.setBaseSize(1000,1000);
    displayDerivatives.exec();
    displayDerivatives2.setWindowTitle("Derivatives Page Two");
    displayDerivatives2.setText("Derivatives Page Two");
    displayDerivatives2.setIconPixmap(pm2);
    displayDerivatives2.icon();
    displayDerivatives2.setBaseSize(1000,1000);
    displayDerivatives2.exec();
    displayDerivatives3.setWindowTitle("Derivatives Page Three");
    displayDerivatives3.setText("Derivatives Page Three");
    displayDerivatives3.setIconPixmap(pm3);
    displayDerivatives3.icon();
    displayDerivatives3.setBaseSize(1000,1000);
    displayDerivatives3.exec();
    displayDerivatives4.setWindowTitle("Derivatives Page Four");
    displayDerivatives4.setText("Derivatives Page Four");
    displayDerivatives4.setIconPixmap(pm4);
    displayDerivatives4.icon();
    displayDerivatives4.setBaseSize(1000,1000);
    displayDerivatives4.exec();
}
///locate resource file for the integrals
/// display message box displaying the functions
/// set the title
/// set the size
/// set the pixMaps
/// show the final message box
void mathDefinitions::integrals()
{
    QImage img1(":/resources/images/Int1.png");
    QPixmap pm = QPixmap::fromImage(img1);
        pm = pm.scaled(800, 800, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QImage img2(":/resources/images/Int2.png");
    QPixmap pm2 = QPixmap::fromImage(img2);
        pm2 = pm2.scaled(800, 800, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QImage img3(":/resources/images/Int3.png");
    QPixmap pm3 = QPixmap::fromImage(img3);
        pm3 = pm3.scaled(800, 800, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QImage img4(":/resources/images/Int4.png");
    QPixmap pm4 = QPixmap::fromImage(img4);
        pm4 = pm4.scaled(800, 800, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QImage img5(":/resources/images/Int5.png");
    QPixmap pm5 = QPixmap::fromImage(img5);
    pm5 = pm5.scaled(800, 800, Qt::KeepAspectRatio, Qt::SmoothTransformation);



    QMessageBox displayIntegrals;
    QMessageBox displayIntegrals2;
    QMessageBox displayIntegrals3;
    QMessageBox displayIntegrals4;
    QMessageBox displayIntegrals5;

    displayIntegrals.setWindowTitle("Integrals");
    displayIntegrals.setText("Integrals Page One");
    displayIntegrals.setIconPixmap(pm);
    displayIntegrals.icon();
    displayIntegrals.setBaseSize(1000,1000);
    displayIntegrals.exec();
    displayIntegrals2.setWindowTitle("Integrals Page Two");
    displayIntegrals2.setText("Integrals Page Two");
    displayIntegrals2.setIconPixmap(pm2);
    displayIntegrals2.icon();
    displayIntegrals2.setBaseSize(1000,1000);
    displayIntegrals2.exec();
    displayIntegrals3.setWindowTitle("Integrals Page Three");
    displayIntegrals3.setText("Integrals Page Three");
    displayIntegrals3.setIconPixmap(pm3);
    displayIntegrals3.icon();
    displayIntegrals3.setBaseSize(1000,1000);
    displayIntegrals3.exec();
    displayIntegrals4.setWindowTitle("Integrals Page Four");
    displayIntegrals4.setText("Integrals Page Four");
    displayIntegrals4.setIconPixmap(pm4);
    displayIntegrals4.icon();
    displayIntegrals4.setBaseSize(1000,1000);
    displayIntegrals4.exec();
    displayIntegrals5.setWindowTitle("Integrals Page Five");
    displayIntegrals5.setText("Integrals Page Five");
    displayIntegrals5.setIconPixmap(pm5);
    displayIntegrals5.icon();
    displayIntegrals5.setBaseSize(1000,1000);

    displayIntegrals5.exec();

}
