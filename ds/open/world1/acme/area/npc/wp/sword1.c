#include <weapon.h>
inherit SWORD;
void create()
{
set_name("木劍",({"sword"}));
set("long","這是一把小孩子玩騎馬打杖的木劍。\n");
set_weight(900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",600);
set("material","iron");
        }
init_sword(5);
        setup();
}
