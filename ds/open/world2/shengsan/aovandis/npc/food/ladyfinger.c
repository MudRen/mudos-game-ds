
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("鬆餅", ({ "ladyfinger" }) );
	set_weight(330);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long","這個鬆餅看起來就很好吃。\n");
	set("unit", "塊");
	}
	set("value",80);
	set("food_remaining",3);
        set("heal_ap",15);
 setup();
}
