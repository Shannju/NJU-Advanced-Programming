#ifndef GRAPHSCENE_H
#define GRAPHSCENE_H

#include <QGraphicsScene>
#include<Marcos.h>
#include<fstream>
#include <vector>
#include<QPixmap>
#include<Marcos.h>
#include<QGraphicsItem>
#include<QMessageBox>

class object;
class student;
class gezi;
class classroom;
class ddl;
class Card;

class Map
{
public:
    vector<vector<int>> a;
    int colunm;
    int row;
    Map();
    Map(int r,int c);
    void init();
    void read_file();
    void write_file();
    void print_file();
    pair<int,int> startPos;
};


class GraphScene : public QGraphicsScene
{
private:
    int u,l;
    int space;
    int side;


public:
    int money=10000;
    int a=0,b=0,c=0,d=0;
    Map* m;
    QList<QList<gezi*>> map;
    QList <student*>stu;
    QList <classroom*>cla;
    QList <ddl*>ddls;
    QList<Card*> card_list;

    QGraphicsTextItem* moneytext;;

    Card*  currentCard = nullptr;
    explicit GraphScene(QObject *parent = nullptr);
    void ms();
    void init();
    void load_map();
    void setmoney(int m);
    pair<int,int>get_abs(int r, int c );
    pair<int,int>get_rela(int x, int y );
    gezi* get_gezi(int x, int y );
    void advance(int phase);
    void newEnemy();
    void addCard(Card* c = nullptr);

};

#include<object.h>

#endif // GRAPHSCENE_H
