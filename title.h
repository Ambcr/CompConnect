#ifndef TITLE_H
#define TITLE_H

#include <QWidget>

class title : public QWidget
{
    Q_OBJECT
public:
    explicit title(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    /* custom title bar */
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

signals:


private:
    bool leftBtnClk=false;
    QPoint m_Press,m_Move;
    QWidget* m_Parent;
};

#endif // TITLE_H
