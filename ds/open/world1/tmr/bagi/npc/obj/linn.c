inherit ITEM;

void create()
{
	set_name("鐵線草",({"adiantum flabellulatum linn","linn"}) );
	set_weight(80);
	set("long",@long
鐵線草為鐵線蕨科多年生植物，高約20至50厘米。生於山溝或林下潮
灦之地。藥用全草，全年可採洗淨切段曬乾備用。其味淡苦，性微涼。清
熱利灦，袪瘀消腫。
long
);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","株");
		set("value",50);
	}
	setup();
}