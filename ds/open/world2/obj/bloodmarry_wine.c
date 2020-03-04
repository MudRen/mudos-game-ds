inherit ITEM;
inherit F_WATER;
void create()
{
	function f;
	set_name("血腥瑪麗", ({ "blood marry wine","blood","marry","wine" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",@LONG
一杯紅色的調酒，雖然加了不少果汁，但是喝多了還是會醉的。
LONG);
		set("unit", "杯");
	}
	set("value", 180);    
	set("heal_mp",40);
	set("heal_ap",40);
	set("water_remaining", 1);
	setup();
	f = (: call_other, __FILE__, "do_drunk" :);
	set("water/function",f);
}

int do_drunk()
{
	this_player()->apply_condition("drunk", this_player()->query_condition("drunk")+7);
	return 1;
}