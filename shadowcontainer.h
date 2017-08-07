#ifndef SHADOWCONTAINER_H
#define SHADOWCONTAINER_H
#include <QFrame>

class ShadowContainer : public QFrame
{
public:
    ShadowContainer(QWidget* p);
    void addWidget(QWidget* addin);
protected:
    void paintEvent(QPaintEvent*e);
};

#endif // SHADOWCONTAINER_H
