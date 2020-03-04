#include <ansi.h>
inherit ITEM;
inherit F_WATER;

void create()
{
        set_name(YEL"威士忌"NOR, ({ "whisky" }) );
        set_weight(1000);
        if( clonep() )
        	set_default_object(__FILE__);
        else
        {
    		set("long", "這是一瓶十分受酒吧歡迎的飲料，喝(drink)了會回復很多體力。\n");
      		set("unit", "瓶");
		set("drink_msg","$N拿起一瓶$n，咕嚕咕嚕地喝了幾口。\n");
		set("finish_drink_msg","$N把餘下的$n喝光了。\n");
     	    	set("value",500);
        		set("heal_ap",50);
		set("heal_hp",50);
        		set("heal_mp",50);
	    	set("water_remaining", 10);
}
}	
void init()
{
	add_action("do_drink", "drink");
}

int do_drink(string arg)
{
	object me;
	if( !this_object() ) return 0;
	if( !this_object()->id(arg) ) return 0;
	me=this_player();
    	if(me->query("age")<18)
	{return notify_fail(HIR"小孩子是不應該喝酒的。\n"NOR);
	}
	else return ::do_drink(arg);
}
