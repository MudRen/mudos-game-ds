#include <armor.h>
inherit ARMOR;
void create()
{
	set_name("硬皮甲", ({ "incrystate armor", "armor" , "incrystate","硬皮甲"  }) );
	set("long",
		"這是在較大型城市所售賣的防具，擁有還不錯的防禦力，不過對於\n"
		"法術等攻擊就沒有防禦可言。\n");
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "副" );
		set("armor_prop/armor",  6);
	set("material","leather");
		set("volume",4);
		set("limit_dex",4);
		set("value", 1800);
	}
	setup();
}
