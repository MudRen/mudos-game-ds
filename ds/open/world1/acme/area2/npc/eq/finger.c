#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name("虎形戒" ,({ "tiger finger","finger" }) );
        set("long","這是一只上頭刻著猛虎樣子的戒指。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(500);
        set("material", "jade");
        set("unit", "只" );
       set("value",750);
        set("armor_prop/armor", 1);
        set("limit_int",10);
        set("armor_prop/con",2);
        set("armor_prop/str",-1);
        }
        setup();
}
