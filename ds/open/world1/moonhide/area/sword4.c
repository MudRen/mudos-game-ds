#include <weapon.h>
inherit SWORD;
void create()
{
        set_name("螢晶刃", ({ "light sword" , "sword" }) );
        set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",2);
                set("unit", "把");
                set("long", "一把很輕的劍  似透明。\n");
                set("value", 2000);
        }
        init_sword(45);
        setup();
}

