#include <weapon.h>
inherit DAGGER;
void create()
{
set_name("鐵尺",({"iron ruler","ruler"}));
set("long","這是一把沉重的長尺，似乎是用上好的赤鐵所打造而成的。\n");
set_weight(4000);   //設重量
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("limit_int",10);
set("unit", "把");
set("value",500);
set("material","iron");
        }
init_dagger(30);
        setup();
}
