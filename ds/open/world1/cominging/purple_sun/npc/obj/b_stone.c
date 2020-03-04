inherit ITEM;

void create()
{
	set_name("大落石", ({ "rockslide", "stone", "stack-road" }));
	set("long", "一個很大的落石, 是從山上滑落下來的. \n");
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "個");
		set("value", 0);
		set("no_sac", 1);
		set("no_get", 1);
		set("no_sell",1);
	}
	setup();
}