#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����",({ "dwller" }));
        set("long","�@�ӵL�~�L�{�������C\n");
        set("level",5);
        set("title",HIM"�m�������n"NOR);
        set("age",15);
        set("gender","�k��");
        setup();
        add_money("coin",300);
      carry_object(__DIR__"obj/whip1")->wield();
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

