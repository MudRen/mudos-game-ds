#include <armor.h>
#include <ansi.h>
inherit MASK;

void create()
{
        set_name(HIW+BLK"蝠形面罩"NOR,({ "bat mask","mask" }) );
        set("long","這個面具外形像個張開雙翼的蝙蝠，能完全保護臉部•\n");
        set_weight(780);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material","fur");
        set("unit","張");
        set("value",780);
        set("limit_lv",25);
        set("limit_int",15);
        }
        set("armor_prop/armor",5);
        set("armor_prop/str",2);
        set("armor_prop/con",1);
        setup();
}

