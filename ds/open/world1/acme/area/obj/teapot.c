inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("奉水茶壺", ({ "tea pot","pot" }) );
        set_weight(9900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_get",1);
                set("no_sac",1);
                set("long", "一個奉水茶壺，置放在椅上，給過往的人飲用。\n");
                set("unit", "個");
                set("value", 20);
                set("heal_ap",45+random(6));
                set("heal_mp",45+random(6));
                set("heal_hp",45+random(6));
                set("water_remaining",50);
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
return notify_fail("你注意到奉水茶壺上貼了張佈告: 本用水只提供等級低於五級的玩家飲用。\n");
        }
        else return ::do_drink(arg);
}
