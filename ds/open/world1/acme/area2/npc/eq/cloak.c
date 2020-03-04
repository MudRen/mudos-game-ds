#include <armor.h>
inherit SURCOAT;
void create()
{
        set_name("硬皮甲斗蓬" ,({ "sky cloak","cloak" }) );
        set("long","這件斗蓬全部是用一片一片的硬皮甲所環扣而成的，\n"
                   "十分具耐用性，美中不足的是過重了。\n");
        set_weight(10000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "leather");
	set("volume",3);
        set("unit", "件" );
        set("value",1500);
        set("limit_lv",15);
	}
        set("armor_prop/armor",11);
        set("armor_prop/dodge",-15);
        setup();
}
