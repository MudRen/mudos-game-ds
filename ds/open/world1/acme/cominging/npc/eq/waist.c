#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
	set_name("黑色束腰" ,({ "blackre waist","waist" }) );
	set("long","這是一條官兵所穿載的腰帶。\n");
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set_weight(100);
        set("material","cloth");
		set("unit", "條" );
		set("value",400);
		set("armor_prop/armor", 2);
		set("armor_prop/hit",1);
	}
	setup();
}
