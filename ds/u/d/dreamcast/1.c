#include <weapon.h>
inherit SWORD;
#include <ansi.h>
void create()
{
        set_name(HIC"天劍"NOR, ({ "sky sword","sword"} ) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",2);
                set("unit", "把");
        set("material","diamond");
                set("long", "這是一把大神用的劍。\n");
                set("value", 1000);
        }
        init_sword(100);
        setup();
}
