inherit ITEM;
inherit F_WATER;
void create()
{
	set_name("燒刀子", ({ "burn blade wine","wine" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	      set("long","這種酒十分辛辣濃烈，不是心情鬱悶，或\n"
		"是「為情所困」之人是不會去嘗試的。\n");
	      set("unit", "瓶");
	      set("value", 150);       
	      set("heal_ap",10);
	      set("water_remaining", 5);
	}
	setup();
}
