inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("鬼鵰肉",({"chisel meat","meat"}) );
	set("long","一片從鬼鵰身上除下來的肉，黑白交錯，不知能不能吃。");
	set_weight(200);	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","片");
		set("value",500);
          set("food_remaining",5);
          set("heal_ap",30);
	}
	setup();

}
