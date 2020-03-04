#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
        set_name(GRN "青鋼鎧甲" NOR,({"guard plate","plate"}) );
        set("long","一件官兵的制式戰甲，具有一定的防禦能力。\n");
        set_weight(7500);
        set("unit","套");
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","套");
        set("value",1000);           
        set("limit_con",18);
        set("limit_str",15);
        set("armor_prop/dex",-1);
        set("armor_prop/con",3);
                set("material","iron");
                set("armor_prop/armor",12);
        }
        setup();
}
