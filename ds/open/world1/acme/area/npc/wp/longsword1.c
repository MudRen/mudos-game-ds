#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name("昊戠長劍" ,({ "hao chi sword","sword" }) );
        set("long","這是一個官兵常配戴的防身長劍。\n");
        set_weight(10000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material","iron");
        }
        set("unit", "把" );
         set("limit_str",10);
       set("value",1500);
set("volume",2);
//        setup();  靠~~ 順序亂放..
//init_sword(25);
	init_sword(25);
	setup();
}
