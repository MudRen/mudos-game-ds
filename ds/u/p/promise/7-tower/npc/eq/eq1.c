#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIR"皓日舞靴"NOR, ({ "sun boots","boots" }) );
        set_weight(4000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","江湖巧手步六弧得意名作之一。\n");
                set("unit", "雙");
                set("value",7000);
                set("material","fur");
                set("armor_prop/dex",1);
                set("armor_prop/int",1);
                set("armor_prop/armor", 17);
                set("limit_lv",40);
                set("limit_dex",50);
                set("limit_con",50);
        }
        setup();
}

