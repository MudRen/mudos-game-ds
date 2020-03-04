#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name("錦衣", ({ "cloth" }) );
	set_weight(3500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","此衣較為緊身, 是練武者常穿的衣服, 不過此衣布料卻\n"
			   "十分的精巧好看, 應該是有錢人家在穿的衣料.\n");
		set("unit", "件");
		set("material", "cloth");
		set("value",500);
	}
	set("armor_prop/shield",2);
	set("armor_prop/armor", 4);
	setup();
}
