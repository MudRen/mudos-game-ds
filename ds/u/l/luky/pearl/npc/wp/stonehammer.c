#include <ansi.h>
#include <weapon.h>
inherit HAMMER;
void create()
{
set_name("石槌",({"stone hammer","hammer"}));
set_weight(26500);
     if( clonep() )
               set_default_object(__FILE__);
     else {
            set("long","看到這把沉重又結實的大石槌, 彷彿時光又回到了石器時代。\n");
            set("unit", "把");
            set("rigidity",97); //硬度
            set("material","stone"); //材質
set("hammer",48);
set("weapon_prop/dex",-3);
set("weapon_prop/mus",5);
set("value",5250);
           }
init_hammer(769);
        setup();
}



