#include <armor.h>
#include <ansi.h>
inherit SHIELD;
void create()
{
        set_name("坎水銀盾" ,({ "water shield","shield" }) );
        set("long","這是神武教護法之一坎水將所裝備的銀盾。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(10000);
        set("limit_str",10);
        set("material", "silver");
        set("unit", "個" );
       set("value",2250);
        set_temp("apply/hit", -4);
        set_temp("apply/armor", 15);
		set("volume",2);
        set("armor_prop/dex",-2);
        }
        setup();
}
