#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
inherit F_UNIQUE;
void create()
{
	set_name(HIC"天龍戰袍"NOR, ({ "dragon cloak","cloak" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這件袍上鏽著三調巨龍, 霸氣十足, 應該是軍家頭目常\n"
                           "披掛上陣的戰袍.\n");
		set("unit", "件");
		set("value",18000);
		set("material","cloth");
		set("limit_con",10);
		set("limit_dex",40);
		set("replica_ob",__DIR__"cloak.c");
	}
	set("armor_prop/armor",12);
	set("armor_prop/shield",10);
	setup();
}
