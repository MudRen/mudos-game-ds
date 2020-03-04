inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("茶水", ({ "tea water","water","tea" }) );
        set_weight(9900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_get",1);
                set("no_sac",1);
                set("long", "一個茶水，置放在桌子上，給靈幻教的教徒飲用。\n");
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
        if(me->query("family_name") == "靈幻教")
        {
return notify_fail("你不是靈幻教徒不能喝。\n");
        }
        else return ::do_drink(arg);
}

