#ifndef EQUATIONSAREA_H
#define EQUATIONSAREA_H
#include <QPaintEvent>
#include <QPainter>
#include <math.h>
#include <QWidget>
#include <QColor>
#include <QSize>
class EquationsArea : public QWidget
{
    Q_OBJECT
public:
    explicit EquationsArea(QWidget *parent = nullptr);

    ///Enumeration of graph type that will be used in switch case to draw matching graph type
    enum graph_type
    {
        Line,
        Parabola,
        Sqrt,
        XReciprical,
        xAxis,
        yAxis
        };

    ///setter that will set graph and load changes to widget on main window
    void set_up_Graph(graph_type graph)
    {
        Graph = graph;
        load_graph_change();
    }

     ///Function that will draw graph selected in equationsarea widget on main window
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

    ///each function will draw a graph defined by the math functions they represent
    /// using float rather then double to ensure greatest accuracy
    QPointF drawLine(float t);
    QPointF drawParabola(float t);
    QPointF drawSQRT(float t);
    QPointF drawXReciprical(float t);
    QPointF drawXAxis(float t);
    QPointF drawYAxis(float t);
    QPointF drawGeneral(float t);

    ///Function to set graph scale, length of interval and step count
    void load_graph_change();

protected:
    ///floating point to represent the length of the shape for the setting set by the user
    float length_of_Interval;
    ///scaler floating point to expand the shape
    float Scale;
    ///stepper to redraw the shape
    int step_count_of_shape;
    ///use Qcolor class to allow the background color to be changed
    QColor background_color;
    ///set up the color of the shape
    QColor graph_color;
    ///initialize enum graph type variable
    graph_type Graph; 
};

#endif // EQUATIONSAREA_H
