inherit ITEM;
void create()
{
	set_name("紅龍花", ({ "red-dragon flower", "flower" }));
	set("long", "紅龍花是一種可以製成紫龍草的花種。\n");
	set("weight", 300);
	if( clonep() ) 
		set_default_object(__FILE__);
	else {
		set("unit", "株");
		set("value", 1);
	}
	setup();
}