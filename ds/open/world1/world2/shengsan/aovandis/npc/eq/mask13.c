#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
	set_name("口罩", ({ "mask" }) );
	set("long",@LONG
這是一副白色的口罩。
LONG
);
	set_weight(1300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "副");
		set("material", "cloth");
	}
	set("auto_set",2);
	setup();
}

//int query_autoload() { return 1; }
