#include <ansi.h>
inherit NPC;
void create()
{
        set_name("記名弟子",({ "apprentice" }));
        set("long","一位天山雪準備收的小弟子。\n");
        set("level",10);
        set("gender","女性");
        set("title",HIM"《情城池》"NOR);
        set("age",19);
        setup();
        add_money("coin",300);
        carry_object(__DIR__"obj/whip4")->wield();
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

