inherit ITEM;

void create()
{
	set_name("天師道符", ({ "taoist charm", "charm" }));
	set("long", "道士在施法時所用的道符。\n");
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "張");
		set("value", 100);
	}
	setup();
}