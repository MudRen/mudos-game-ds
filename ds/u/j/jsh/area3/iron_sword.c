#include <ansi.h>
#include <weapon.h>  
inherit SWORD;
void create()
{
        set_name(WHT"鐵劍"NOR, ({ "iron sword" , "sword" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
                set("unit", "把");
                set("long", "一把用鐵鑄成的劍。\n");
                set("value", 3000);
        }
        init_sword(50);
        setup();
}

