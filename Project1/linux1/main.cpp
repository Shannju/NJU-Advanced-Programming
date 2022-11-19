#include "menu.h"
#include "structure.h"
using namespace std;
int main()
{
    file<User> fu("userfile");
    file<Goods> fg("goodsfile");
    file<Order> fo("orderfile");
    fu.open();
    fg.open();
    fo.open();
    MainMenu m = MainMenu(&fu, &fg, &fo);
    m.halt();
    return 0;
}
