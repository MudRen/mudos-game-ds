#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name(HIR"可口可樂-布衣"NOR, ({ "CocaCola","cloth" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","一件有一定防護力的皮衣。\n");
		set("unit", "件");
		set("material", "cloth");
//		set("no_drop",1);
		set("no_sac",1);
		set("value",15000);
		set("armor_prop/parry",2);
		set("armor_prop/armor",4);
	}
	setup();
}

int query_autoload() { return 1; }