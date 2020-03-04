#include <armor.h>
#include <ansi.h>
inherit WAIST;
inherit F_UNIQUE;
void create()
{
	set_name(HIC"天龍腰帶"NOR, ({ "dragon belt","belt" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這是件鏽有一條天龍的皮腰帶, 不知有什麼神奇的功用.\n");
		set("unit", "條");
		set("value",12000);
		set("material", "cloth");
		set("replica_ob",__DIR__"belt.c");
	}
	set("armor_prop/armor", 3);
	set("armor_prop/shield",30);
	setup();
}
