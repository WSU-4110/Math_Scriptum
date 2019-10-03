#ifndef SHAPEAREA_H
#define SHAPEAREA_H
#include <QPaintEvent>
#include <QPainter>
#include <math.h>
#include <QWidget>

class ShapeArea : public QWidget
{
    Q_OBJECT
public:
    explicit ShapeArea(QWidget *parent = nullptr);
    ///override functions from base class needed to have the custom widget bhave accordingly
   //QSize minimumSizeHint() const Q_DECL_OVERRIDE;
   //QSize sizeHint() const Q_DECL_OVERRIDE;
    //bug 001



signals:

public slots:
};

#endif // SHAPEAREA_H
