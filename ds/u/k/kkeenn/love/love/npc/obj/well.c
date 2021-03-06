inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("水井", ({ "well" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_get",1);
                set("no_sac",1);
                set("long", "一口井，給過往的城民們飲用。\n");
                set("unit", "口");
                set("value", 0);
                set("heal_ap",10);
                set("heal_mp",10);
                set("heal_hp",10);
                set("water_remaining",70);
                set("drink_msg","$N打了一桶水井裡的水，咕嚕咕嚕~~好好喝歐。\n");
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
    if(me->query("level")>10)
        {
return notify_fail("你注意到井旁上貼了張佈告: 本井只提供等級十級以下的玩家
飲用。\n");
        }
        else 
        {
                set("heal_ap",50+random(5));
                set("heal_mp",50+random(5));
                set("heal_hp",50+random(10));
                return ::do_drink(arg);
        }
}

