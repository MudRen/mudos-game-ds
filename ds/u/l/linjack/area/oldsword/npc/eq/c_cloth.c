#include <armor.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit CLOTH;
void create()
{
	set_name(HIW"雲袍"NOR, ({ "cloud cloth","cloth" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這件衣服特製的材質和縫製方法, 讓它變成輕而強韌\n"
                           "的高防禦力衣物, 據說普天之下只有雲天翔身上的這一件.\n");
		set("unit", "件");
		set("value",15000);
		set("material","cloth");
		set("limit_con",10);
		set("limit_int",15);
		set("replica_ob",__DIR__"c_cloth_f");
	}
	set("armor_prop/dex",1);
	set("armor_prop/dodge",5);
	set("armor_prop/armor",18);
	set("armor_prop/show_damage",1);
	setup();
}
