#include <ansi.h>
inherit ITEM;
inherit F_WATER;

void create()
{
	set_name(YEL"�@�~�~���s�|"NOR,({"wine bodega","wine","bodega"}));
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�@���|���s�b�̭��a���A�A�i�H�յۥ�(potation)�ܳܬݡC\n");
		set("unit","��");
		set("no_get",1);
		set("no_sac",1);
		set("value",1);
//		set("heal_mp",random(10));
//		set("heal_ap",1+random(10));
//		set("water_remaining",30);
	}
	setup();
}