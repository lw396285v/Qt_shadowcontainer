#ifndef SHADOWCONTAINER_H
#define SHADOWCONTAINER_H
#include <QFrame>

class ShadowContainer : public QFrame
{
public:
    ShadowContainer(int m,int r,QWidget* p);
    void addWidget(QWidget* addin);
protected:
    void paintEvent(QPaintEvent*e);
private:
    int margin = 0;
    int radius = 0;
};

#endif // SHADOWCONTAINER_H
