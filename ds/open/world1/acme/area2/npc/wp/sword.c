#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIW "繞指柔劍" NOR , ({ "around fingers sword","sword" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "把");
               set("long", "這是一把細長的劍，遍體通白，十分柔軟，但並不是很重。\n");
               set("value",1200);
               set("limit_int",5);
		set("volume",2);
               set("material", "copper");
        }
    init_sword(24);
   setup();
}
