inherit ITEM;
void create()
{
	set_name("紅水晶",({ "red crystal","crystal" }) );
	set_weight(700);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long",@LONG
一塊紅色的水晶碎片。

LONG);
		set("unit", "塊");
		set("material","glass");
	}
	setup();
	set("value",1000);
	set("volume",1);
}
int is_crystal() { return 1; }