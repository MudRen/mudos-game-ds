// dumpling.c

inherit ITEM;
inherit F_WATER;

void create()
{
	set_name("啤酒", ({ "beer" }) );
	set_weight(60);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一瓶很普通的啤酒。\n");
		set("unit", "瓶");
		set("value", 16);	//參考價格為回復點數總和除以5
		set("heal_mp",20);	//可以是"heal_hp"或是"heal_mp",也可以都有.
		set("water_remaining", 3);
	}
	setup();
}
