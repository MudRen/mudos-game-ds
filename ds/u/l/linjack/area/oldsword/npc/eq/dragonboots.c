#include <armor.h>
#include <ansi.h>
inherit BOOTS;
inherit F_UNIQUE;
void create()
{
	set_name(HIC"天龍戰靴"NOR, ({ "dragon boots","boots" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這雙鞋上左右兩側都各鏽了條龍, 你光看就覺得有點\n"
                           "騰雲駕霧的感覺了, 不知道這雙鞋有什麼特別的功用??\n");
		set("unit", "雙");
		set("value",10000);
		set("material","cloth");
		set("limit_dex",35);
		set("limit_int",25);
		set("replica_ob",__DIR__"boots.c");
	}
	set("armor_prop/dex",1);
	set("armor_prop/armor",8);
	set("armor_prop/shield",4);
	setup();
}
