inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("木桶水缸", ({ "pot" }) );
        set_weight(9900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("no_get",1);
		set("no_sac",1);
                set("long", "一個大水缸，置放在地上，給過往的人飲用。\n");
                set("unit", "缸");
                set("value", 20);
                set("heal_ap",10);
                set("heal_mp",10);
                set("heal_hp",10);
                set("water_remaining",50);
                set("drink_msg","$N彎下腰喝了幾口$n裡的茶水。\n");
        }
        
        setup();
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
    if(me->query("level")>5)
	{
return notify_fail("你注意到水缸上貼了張佈告: 本用水只提供等級五級以下的玩家
飲用。\n");
	}
	else 
	{
		set("heal_ap",40+random(10));
                set("heal_mp",40+random(10));
                set("heal_hp",40+random(10));
		return ::do_drink(arg);
	}
}
