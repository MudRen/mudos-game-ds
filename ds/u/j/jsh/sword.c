#include <weapon.h>
inherit SWORD;
void create()
{
        set_name("氣勁劍", ({ "ap sword" , "sword" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",2);
                set("unit", "把"); 
                set("no_sell",1);
                set("no_drop",1);
                set("no_give",1); 
                set("no_get",1);                set("long", "由氣勁所凝聚而成的劍。\n");
        }
        init_sword(1);
        setup();
}


