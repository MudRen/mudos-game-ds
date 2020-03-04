#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name("錦袍", ({ "robe" }) );
	set_weight(4500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","此衣較為寬敞, 而此衣料十分高級, 應該是有錢人家在穿的衣服,\n"
			   "不過瞧真一點, 這袍的袖口是較緊的, 不知道因何有這樣怪的設計?\n");
		set("unit", "件");
		set("material", "cloth");
		set("value",1000);
	}
	set("armor_prop/shield",2);
	set("armor_prop/armor", 5);
	setup();
}
