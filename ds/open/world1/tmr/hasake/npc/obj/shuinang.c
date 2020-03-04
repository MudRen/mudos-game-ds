// shuinang.c  水囊

inherit ITEM;
inherit F_WATER;

void create()
{
	set_name("水囊", ({"water skin", "skin"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "這是裝滿清水的水囊。\n");
		set("unit", "只");
		set("value", 350);
        set("heal_mp", 5);
		set("water_remaining", 7);

	}
}
