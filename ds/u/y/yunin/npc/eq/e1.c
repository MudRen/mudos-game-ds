#include <ansi.h>

#include <armor.h>

inherit SHIELD;



void create()

{

        set_name(HIC"冰天盾"NOR,({"ice of sky","ice"}) );

        set("long",@LONG

月狼子月百年修為創造出來的盾牌。

LONG

);

        set_weight(2000);

        if( clonep() )

                set_default_object(__FILE__);

        else {

                set("limit_str",21);

                set("unit", "個");

                set("value",5000);

                set("volume", 4);

                set("material", "cold");

        }

        set("armor_prop/armor",25);



 set("armor_prop/shield",17);

        setup();

}
