#include "title.h"
#include<QPainter>
#include<QStyleOption>
#include<QMouseEvent>
#include "ui_mainwindow.h"
#include<QDebug>

title::title(QWidget *parent) : QWidget(parent)
{
    m_Parent=parent;
}
void title::paintEvent(QPaintEvent *event)

{

    Q_UNUSED(event);



    QStyleOption opt;

    opt.init(this);

    QPainter p(this);

    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

}

void title::mousePressEvent(QMouseEvent *event)
{

    if( event->button() == Qt::LeftButton){
        m_Press = event->globalPos();
        //qDebug()<<"press  x:"<<m_Press.x()<<"y:"<<m_Press.y();
        leftBtnClk = true;
    }
    event->ignore();//表示继续向下传递事件，其他的控件还可以去获取
}

void title::mouseReleaseEvent(QMouseEvent *event)
{

    if( event->button() == Qt::LeftButton ){
        leftBtnClk = false;
    }
    event->ignore();
}

void title::mouseMoveEvent(QMouseEvent *event)
{
    if( leftBtnClk ){
        m_Move = event->globalPos();
        //qDebug()<<"move  x:"<<m_Move.x()<<"y:"<<m_Move.y();
        m_Parent->move( m_Parent->pos() + m_Move - m_Press );
        m_Press = m_Move;
    }
    event->ignore();
}
