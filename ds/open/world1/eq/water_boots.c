#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIC"踩水靴"NOR, ({ "boots" }) );
        set_weight(3500);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","這是一雙相當輕的靴子, 看來可以提供相當的防護.\n");
                set("unit", "雙");
                set("material","fur");
	set("value",3000);
	 set("armor_prop/dex",2);
                set("armor_prop/shield",1);
                set("armor_prop/armor", 14);
        }
        setup();
}
