inherit ITEM;
inherit F_WATER;
void create()
{
	set_name("啤酒", ({ "beer" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","一種大麥釀成的酒類。\n");
		set("unit", "瓶");
		set("value", 180);    
		set("heal_mp",20);
		set("water_remaining", 3);
	}
	setup();
}
