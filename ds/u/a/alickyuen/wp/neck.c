#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
	set_name(HIR"可口可樂-鍊"NOR, ({ "CocaCola","necklace" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","看起來像是道行高身的巫師所配帶的東西,\n"
                           "對法術的抵抗力有相當的威力,是可口可樂專用的。\n");
		set("unit", "條");
		set("material", "cloth");
//		set("no_drop",1);
		set("no_sac",1);
		set("value",30000);
		set("armor_prop/wit",2);
		set("armor_prop/sou",1);
		set("armor_prop/int",4);
		set("armor_prop/shield",15);
		set("armor_prop/armor", 1);
	}
	setup();
}

int query_autoload() { return 1; }