#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
	set_name("太陽眼鏡", ({ "presbyopic glasses","glasses" }) );
	set("long",@LONG
這是一副老年人所戴的老花眼鏡。
LONG
);
	set_weight(750);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "副");
		set("material", "glass");
	}
	set("armor_prop/armor",2);
//	set("armor_prop/show_damage",1);
	setup();
	set("value",880);
}

int query_autoload() { return 1; }
