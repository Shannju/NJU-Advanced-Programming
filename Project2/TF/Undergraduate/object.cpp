#include "object.h"
#include<QLabel>

class zObject : public QLabel
{
    Q_OBJECT
public:
    explicit zObject(QWidget* parent = 0);
    bool alive = true;
    virtual void act()=0;
    int strength = 1;
//    Scene* scene;
};
