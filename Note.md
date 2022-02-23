# 项目记录

## 创建UI界面

**1.固定窗口大小**

```
this->setFixedSize(800,600);
```

2.去掉标题栏

```
setWindowFlags(Qt::FramelessWindowHint);
```

3.设置窗口背景透明

```
this->setAttribute(Qt::WA_TranslucentBackground);
```

4.设置透明色

```
setWindowOpacity(0.7);
```

5.从QWidget提升为QWidget继承类之后，样式表失效

首先要先将样式表中的QWidiget改为你提升后的那个类名，然后重写`paintEvent()`方法

```
void title::paintEvent(QPaintEvent *event)

{

    Q_UNUSED(event);



    QStyleOption opt;

    opt.init(this);

    QPainter p(this);

    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

}
```

6.设置自定义标题栏按住可移动

重写三个方法

```
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
```

7.单机最小化

```
this->setWindowState(Qt::WindowMinimized);
```