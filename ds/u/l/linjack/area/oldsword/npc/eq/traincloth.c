#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("練武服", ({ "training cloth","cloth" }) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這件衣物有點緊身, 是以高級布料做成, 不易扯斷,\n"
                           "十分適合用來練習武術時穿著。\n");
		set("unit", "件");
		set("value",1500);
		set("material", "cloth");
		set("limit_dex",10);
	}
	set("armor_prop/armor",5);
	set("armor_prop/shield",3);
	set("armor_prop/show_damage",1);
	set("armor_prop/int",1);
	set("armor_prop/dex",1);
	setup();
}
