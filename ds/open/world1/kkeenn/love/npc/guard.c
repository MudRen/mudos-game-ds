#include <ansi.h>
inherit NPC;
void create()
{
        set_name("守衛",({ "love guard","guard" }));
        set("long","一位手持精鋼鞭的守衛。\n");
        set("level",20);
        set("gender","女性");
        set("class1","情城池");
        set("title",HIM"《情城池》"NOR);
        set("age",20);
        setup();
        add_money("coin",500);
      carry_object(__DIR__"obj/whip2")->wield();
}

void init()
{       
        object me=this_player();
        object ob=this_object();
        ::init();
      if(me->query_temp("kill_love"))
        {
      ob->kill_ob(me);
                        return;
        }
}
int do_guard(string arg)
{
        if( (arg!= "north") || !this_player()->visible(this_object()) ) return 0;
        write( name() + "將你攔了下來。\n");
      command("grin");
           say("守衛說道："HIR"要滅派？先問問我的鞭吧！\n"NOR);
        return 1;
}

