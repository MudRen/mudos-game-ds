#include <weapon.h> 
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name(HIW"太阿之劍"NOR, ({ "Tai-er sword" , "sword" }) );
        set_weight(3700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",2);
                set("unit", "把"); 
                set("long", "太古神劍，具有強大的神力。\n");
        }
        init_sword(80);
        setup();
}

