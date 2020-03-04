#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
	set_name(HIC"雪羽寶甲"NOR, ({ "ice armor","armor" }) );
	set_weight(11000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這是一件由三千隻雪蟬的羽翼編織而成的透明寶甲。\n[可儲存裝備]\n");
		set("unit", "件");
		set("material", "ice");
		//set("no_sell",1);
		set("no_sac",1);
		set("value",4800);
	}
	set("armor_prop/shield",15);
	set("armor_prop/dodge",5);
	set("armor_prop/armor",20);
	setup();
}

int query_autoload() { return 1; }