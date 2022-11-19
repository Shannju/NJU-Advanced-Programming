#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>

class SubWidget : public QWidget
{
    Q_OBJECT
private:
    QPushButton b;
public:
    explicit SubWidget(QWidget *parent = nullptr);
    void sendSlot();

signals:
    void mysignal();

};

#endif // SUBWIDGET_H
