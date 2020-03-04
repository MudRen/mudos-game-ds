#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
	set_name("夜視眼鏡", ({ "night-vision glasses","glasses" }) );
	set("long",@LONG
這是一副最新科技的夜視眼鏡，可以將微弱的光線加強到眼睛可以看
到的程度。
LONG
);
	set_weight(1050);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "副");
		set("material", "glass");
	}
	set("armor_prop/armor",2);
//	set("armor_prop/show_damage",1);
	setup();
	set("value",2280);
}

int wear()
{
	if(::wear())
	{
		this_object()->start_light(1);
		return 1;
	}
	else return 0;
}

int unequip()
{
	if(::unequip())
	{
		this_object()->start_light(0);
		return 1;
	}
	else return 0;
}

//int query_autoload() { return 1; }
