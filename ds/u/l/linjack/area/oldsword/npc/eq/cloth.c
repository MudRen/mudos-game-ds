#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("����", ({ "cloth" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�@�󷥨�²��������.\n");
		set("unit", "��");
		set("value",200);
		set("material", "cloth");
	}
	set("armor_prop/armor",1);
	set("armor_prop/shield",1);
	setup();
}
