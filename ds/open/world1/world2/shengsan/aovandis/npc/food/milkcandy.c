
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("牛奶糖", ({ "milk candy","milk","candy" }) );
	set_weight(140);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long","小孩子最喜歡的牛奶糖。\n");
	set("unit", "顆");
	}
	set("value",10);
	set("food_remaining",1);
        set("heal_mp",9);
 setup();
}
