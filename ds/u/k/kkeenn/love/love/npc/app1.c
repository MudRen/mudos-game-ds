#include <ansi.h>
inherit NPC;
void create()
{
        set_name("入門弟子",({ "apprentice" }));
        set("long","一位剛被天山雪收入門的小弟子。\n");
        set("level",15);
        set("gender","女性");
        set("title",HIM"《情城池》"NOR);
        set("age",15);
        setup();
        add_money("coin",350);
        carry_object(__DIR__"obj/whip3")->wield();
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

