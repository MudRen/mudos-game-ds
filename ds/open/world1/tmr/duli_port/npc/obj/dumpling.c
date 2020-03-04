// manto.c

inherit COMBINED_ITEM;
inherit F_FOOD;

void create()
{
	set_name("菜包子", ({ "dumpling" }));
	if( !clonep() ) {
		set("unit", "堆");
		set("base_unit", "個");
		set("base_value", 10);
		set("base_weight", 100);
		set("food_stuff", 100);
		set("long", "一個香噴噴的菜包子，約有一個拳頭大，吃起來很有滿足感。\n");
	}
	setup();
}

