#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QObject>
#include <Marcos.h>
#include<graphscene.h>

class MYGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    MYGraphicsView();
    explicit MYGraphicsView(QWidget *parent = nullptr);
    ~MYGraphicsView();
    MYGraphicsView *self(){return m_self;}

protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;/*重写鼠标按下事件*/
//    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
//    void mouseDoubleClickEvent(QMouseEvent *event)Q_DECL_OVERRIDE;

//signals:
//    void mouseMovePoint(QPoint event);
//    void mouseMoveClicked(QPoint event);
//    void mouseDoubleClick(QPoint point);

private:
    static MYGraphicsView *m_self;

};

#endif // MYGRAPHICSVIEW_H
