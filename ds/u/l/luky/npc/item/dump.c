// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("大燒包", ({ "dump" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一個香噴噴、熱騰騰的大燒包。\n");
		set("unit", "個");
		set("value", 18);	//參考價格為回復點數總和除以5
		set("heal_hp",30);	//可以是"heal_hp"或是"heal_mp",也可以都有.
		set("food_remaining", 3);
	}
	setup();
}
