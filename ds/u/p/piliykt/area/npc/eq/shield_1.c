#include <armor.h>
#include <ansi.h>
inherit SHIELD;
void create()
{
        set_name(HIG"青雲盾"NOR ,({ "blue sky shield","shield" }) );
        set("long","這是一個全藍的鋼盾.\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(3200);
        set("material", "crimsonsteel");
        set("unit", "面" );
        set("value",2300);
        set("armor_prop/armor", 18);
                set("volume",5);
        set("limit_str",25);
        set("limit_lv",20);
        }
set("armor_prop/con",1);
set("armor_prop/str",1); 
set("armor_prop/block",10); 
        setup();
}

