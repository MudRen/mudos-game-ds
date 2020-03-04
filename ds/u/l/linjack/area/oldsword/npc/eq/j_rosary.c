#include <armor.h>
#include <ansi.h>
inherit NECK;
inherit F_UNIQUE;
void create()
{
	set_name("玉佛珠", ({ "jade rosary","rosary" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這佛珠還真是十分的高級, 全部用寶玉所串成, 可是\n"
                           "你不禁想想, 既已四大皆空, 要這種俗氣的佛珠何用?\n");
		set("unit", "串");
		set("value",8000);
		set("replica_ob",__DIR__"rosary");
		set("material","jade");
	}
	set("armor_prop/armor",2);
	set("armor_prop/int",3);
	set("armor_prop/wit",1);
	set("armor_prop/tec",-1);
	set("armor_prop/show_damage",1);
	setup();
}
