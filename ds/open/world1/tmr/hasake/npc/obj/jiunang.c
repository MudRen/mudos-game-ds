// jiunang.c  大酒囊

inherit ITEM;
inherit F_WATER;

void create()
{
	set_name("大酒囊", ({"wine skin","skin"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一只是草原牧民的大酒囊，裡面裝滿了香辣的馬奶酒。\n");
		set("unit", "只");
		set("value", 500);
        set("heal_mp", 10);
		set("water_remaining", 5);
	}

}
