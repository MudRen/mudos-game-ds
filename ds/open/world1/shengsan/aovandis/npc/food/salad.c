
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("沙拉",({"salad"}) );
	set_weight(10);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long","你看不出有什麼特別的地方,也許\只是一盤普通的沙拉。\n");
	set("unit", "盤");
	set("value",30);
	set("food_remaining",1);
	}
}
