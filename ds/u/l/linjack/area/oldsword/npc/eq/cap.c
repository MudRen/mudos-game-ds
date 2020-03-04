#include <armor.h>
inherit HEAD;
void create()
{
	set_name("頭巾", ({ "training cap","cap" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","一條練武時綁在頭上的頭巾。\n");
		set("unit", "條");
		set("value",500);
		set("material", "cloth");
		set("limit_int",5);
	}
	set("armor_prop/armor",1);
	set("armor_prop/shield",1);
	set("armor_prop/show_damage",1);
	set("armor_prop/int",1);
	setup();
}
