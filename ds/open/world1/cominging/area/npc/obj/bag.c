inherit ITEM;

void create()
{
	set_name("小布袋", ({ "small bag","bag" }) );
	set_weight(500);
	set_max_capacity(8);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "口");
		set("long", "這是一口尋常的布袋﹐可以用來裝一些雜物。\n");
		set("volume",3);
    set("value",20);
	}
	setup();
}
