#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
        set_name(HIR"地嶽綁手"NOR ,({ "hell holds","holds" }) );
        set("long","一雙沾滿鮮血的手套,蚩尤殺生時都要待著它。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(500);
        set("material", "linen");
        set("unit", "雙" );
        set("value",300);
        }
         set("armor_prop/armor", 10);
         set("armor_prop/shield", 2);
         set("armor_prop/int", -1);
         set("armor_prop/str", 2);
        setup();
}


