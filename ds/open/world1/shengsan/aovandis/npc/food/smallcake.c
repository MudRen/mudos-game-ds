
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("小蛋糕",({ "small cake","small","cake" }) );
	set_weight(50);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long","這個小蛋糕做得蠻精緻的。\n");
	set("unit", "塊");
	set("value",50);
	set("food_remaining",2);
	}
}
