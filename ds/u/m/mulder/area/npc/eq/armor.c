#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name("鋼鐵鎧" ,({ "steel armor","steel","armor" }) );
        set("long","這是用純鋼所煉成的鎧甲。\n");
	set_weight(12000);
        if ( clonep() )
	set_default_object(__FILE__);
        else {
              set("material", "armor");
	set_weight(3000);
	set("value", 4000);
	set("limit_str",15);
	set("unit", "件" );
        set("material","steel");
	set("armor_prop/dodge", -2);
        set("armor_prop/armor", 20);
        set("armor_prop/shield", 5);
        }
        setup();
set("wear_msg", HIG"$N把$n穿在身上，感到這鎧甲十分沉重•\n"NOR);

}	
