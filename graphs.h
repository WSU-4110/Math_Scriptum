#ifndef GRAPHS_H
#define GRAPHS_H
#include <equationsarea.h>
#include <QWidget>
class graph : public EquationsArea
{
    Q_OBJECT
public:
    ///each function will draw a graph defined by the math functions they represent
    static QPointF drawLine(float t);
    static QPointF drawParabola(float t);
    static QPointF drawSQRT(float t);
    static QPointF drawXReciprical(float t);
    static QPointF drawXAxis(float t);
    static QPointF drawYAxis(float t);
    static QPointF drawGeneral(float t);


};

#endif // GRAPHS_H
