#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name(HIW"淨白長袍"NOR,({ "white robe","robe" }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","件");
		set("long",
			"這是一件全白的長袍，由於布料是由純棉所製，所以很好洗\n"
			"也不容易髒，在長袍的側邊繡了一個字「宋」。\n"
		);
		set("material","cloth");
		set("value",200);
		set("armor_prop/armor", 3);
		set("armor_prop/int", 1);
	}
	setup();
}