#include <weapon.h>
inherit SWORD;
void create()
{
        set_name("重劍", ({ "heavy sword" , "sword" }) );
        set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",2);
                set("unit", "把");
                set("long", "一把很重的劍。\n");
                set("value", 2000);
        }
        init_sword(45);
        setup();
}


