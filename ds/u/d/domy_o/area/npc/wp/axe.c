#include <weapon.h>
inherit AXE;

void create()
{
set_name("平斧",({"axe"}));
set("long","這是一般混混幹架常用的小斧頭。\n");
set_weight(8000);   //設重量
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",1500);
set("material","iron");
        }
init_axe(15);
        setup();
}

