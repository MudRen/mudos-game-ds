#include <armor.h>
#include <ansi.h>
inherit SHIELD;
void create()
{
        set_name(YEL"巨蚌盾"NOR ,({ "clam shield","shield" }) );
        set("long","這是一個步六弧用巨蚌殼加上鐵做出來的大盾, 看起來相當的重。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
       set_weight(2000);
        set("material", "iron");
        set("unit", "面" );
      set("value",5400);
        set("armor_prop/armor", 20);
        set("limit_str",15);
        set("armor_prop/con",1);
        }
        setup();
}