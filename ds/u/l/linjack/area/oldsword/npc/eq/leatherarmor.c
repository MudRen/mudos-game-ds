#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
	set_name("軟皮甲", ({ "leather armor","armor" }) );
	set_weight(3500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這件皮甲通常是輕裝甲的官兵或是侍衛所穿的基本\n"
                           "防具, 沒有很大的防禦力, 而且頗容易損壞, 但很輕。\n");
		set("unit", "件");
		set("value",1500);
		set("material","leather");
		set("limit_con",10);
	}
	set("armor_prop/dodge",-5);
	set("armor_prop/shield",3);
	set("armor_prop/armor",6);
	setup();
}
