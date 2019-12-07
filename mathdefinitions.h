#ifndef MATHDEFINITIONS_H
#define MATHDEFINITIONS_H
#include <QObject>
#include <QWidget>

class mathDefinitions
{
public:
    ///call the functions with built in functions
    explicit mathDefinitions(QWidget *parent = nullptr);
    void limit();
    void derivative();
    void integrals();
};

#endif // MATHDEFINITIONS_H
