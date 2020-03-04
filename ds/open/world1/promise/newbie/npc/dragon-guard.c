#include <ansi.h>
inherit NPC;
void create()
{
        set_name("守衛龍"NOR, ({ "dragon guard","dragon","guard" }));
        set("long","管理幼龍塔的守衛。\n");

        set("race","野獸");
        set("level", 1);
        set("no_kill",1);
        set("no_fight",1);
        set("age", 100);

        set("limbs", ({ "龍頭","尾巴","鱗甲","觸角","前腳","後腳","背鰭" }) );
        set("verbs", ({ "bite", "claw","poke" }));


       setup();
        add_money("coin",1000);
}

void init()
{

       ::init();
        add_action("do_guard", "go");
}
int do_guard(string arg, object me)
{ 
        if( (arg!= "enter") || me->query("level") > 15 || !this_player()->visible(this_object()) ) return 0;
        write( name() + "將你攔了下來。\n");
      command("gan");
           say("守衛龍說："HIR"這裡不適合你去，請你留下！！\n"NOR);
        return 1;
}


