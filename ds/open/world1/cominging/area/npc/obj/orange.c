inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("柳橙", ({ "orange" }));
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","一個從平常田中所摘下的水果，可以食用，吃了可以補充體力。\n");
		set("unit","顆");
	}
	set("value", 160);
	set("heal_ap", 20);
	set("water_remaining",2);
	setup();
}