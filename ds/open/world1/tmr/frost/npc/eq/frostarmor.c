#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HBK"寒澈戰鎧"NOR ,({ "frost armor","armor" }) );
        set("long","寒澈派觀主所穿戴的戰鎧。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(38000);
                set("unit","件");
                set("value",10000);
                set("volume",3);
                set("armor_prop/armor", 30);
                set("armor_prop/str", 1);
                set("limit_con",20);
        }
        setup();
}
