#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name("����", ({ "cloth" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�@�󷥨�²��������.\n");
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/shield",2);
		set("armor_prop/armor", 2);
	}
	setup();
}
