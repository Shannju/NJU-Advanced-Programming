#ifndef SQUARE_H
#define SQUARE_H

#include <QWidget>

class Square : public QWidget
{
    Q_OBJECT
public:
    explicit Square(QWidget *parent = nullptr);
//    int heightForWidth ( int w )const{ return w; };
//    bool hasHeightForWidth() const{ return true; };
signals:

};



#endif // SQUARE_H
