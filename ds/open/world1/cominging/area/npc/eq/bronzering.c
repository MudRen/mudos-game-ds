#include <armor.h>
inherit FINGER;
void create()
{
	set_name("青銅指環", ({ "bronze ring", "ring" }) );
	set("long", "一枳上面沾滿的青霉的戒指。\n");
	set_weight(1600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "只" );
		set("armor_prop/armor", 2);
	set("material","copper");
		set("value", 200);
	}
	setup();
}
