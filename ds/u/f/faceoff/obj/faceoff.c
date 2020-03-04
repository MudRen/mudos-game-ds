#include <weapon.h>
#include <ansi.h>

inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("路障 故障事故", ({ "wall" }) );
        set_weight(9900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_get",1);
                set("no_sac",1);
                set("long", "往 Enter 的出口有問題, 請不要走....。\n");
                set("unit", "個");
                set("value", 20);
                set("heal_ap",10);
                set("heal_mp",10);
                set("heal_hp",10);
                set("water_remaining",50);
        }
        
        setup();

}

void init()
{
       add_action("do_enter","enter");
}
     int do_enter(string arg);
{
        object me;
        me=this_player();
      if (arg != "")
      message_vision("$N 被路障擋住, 無法往內移動!!",me);
        return 1;
}


