#include "shadowcontainer.h"
#include <QPainter>
#include <QPainterPath>
#include <QtMath>
#include <QGridLayout>

ShadowContainer::ShadowContainer(QWidget*p):QFrame(p)
{
    setAttribute(Qt::WA_StyledBackground, true);
}

void ShadowContainer::paintEvent(QPaintEvent *e){

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QColor color(0, 0, 0, 50);
    for(int i=0; i<10; i++)
    {
        QPainterPath path;
        path.setFillRule(Qt::WindingFill);
        path.moveTo(margin+radius,margin-i);
        path.arcTo(margin-i,margin-i,2*(i+radius),2*(i+radius),90,90);
        path.lineTo(margin-i,this->height()-margin-radius);
        path.arcTo(margin-i,this->height()-margin-2*radius-i,2*(i+radius),2*(i+radius),180,90);
        path.lineTo(this->width()-margin-radius,this->height()-margin+i);
        path.arcTo(this->width()-margin-2*radius-i,this->height()-margin-2*radius-i,2*(i+radius),2*(i+radius),270,90);
        path.lineTo(this->width()-margin+i,margin+radius);
        path.arcTo(this->width()-margin-2*radius-i,margin-i,2*(i+radius),2*(i+radius),0,90);
        path.closeSubpath();
        color.setAlpha(150 - qSqrt(i)*50);
        painter.setPen(color);
        painter.drawPath(path);
    }
}

void ShadowContainer::addWidget(QWidget* addin){
    this->setFixedSize(addin->size());
    _l->addWidget(addin);
}

void ShadowContainer::setParam(int m,int r){
    margin = m;
    radius = r;
    _l = new QGridLayout(this);
    _l->setMargin(margin);
    this->setLayout(l);
}
