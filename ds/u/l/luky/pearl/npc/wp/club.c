#include <weapon.h>
inherit HAMMER;
void create()
{
set_name("警棍",({"guard club","club"}));
set_weight(27000);
     if( clonep() )
               set_default_object(__FILE__);
     else {
            set("long","\n
一把烏鋼做的警棍。\n");
            set("unit", "把");
            set("rigidity",70); //硬度
            set("material","steel"); //材質
set("hammer",45);
set("value",3750);
           }
// init_hammer(1000);
        setup();
}



