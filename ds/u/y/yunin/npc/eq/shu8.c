#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(HIR"修羅之戒〥"NOR, ({ "shu lo ring","ring" }) );
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","四大塔王之一的燕非彥使用的防具。\n");
                set("unit", "只");
        set("value",3200);
        set_weight(400);
              set("material","jade");
                set("armor_prop/armor", 5);
                 set("armor_prop/con",1);
        }
        setup();
}

