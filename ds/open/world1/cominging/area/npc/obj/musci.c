inherit ITEM;
void create()
{
	set_name("蘚苔",({ "musci" }));
	set_weight(200);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long","一種從陰暗處所刮下的東西。\n");
		set("unit","堆");
		set("value",10);
	}
	setup();
}