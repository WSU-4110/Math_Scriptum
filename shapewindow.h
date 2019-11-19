#ifndef SHAPEWINDOW_H
#define SHAPEWINDOW_H

#include <QDialog>

namespace Ui {
class ShapeWindow;
}

class ShapeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ShapeWindow(QWidget *parent = nullptr);
    ~ShapeWindow();

private:
    Ui::ShapeWindow *ui;
};

#endif // SHAPEWINDOW_H
