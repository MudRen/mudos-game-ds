#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�J���̤l",({ "apprentice" }));
        set("long","�@���Q�Ѥs�����J�����p�̤l�C\n");
        set("level",15);
        set("gender","�k��");
        set("title",HIM"�m�������n"NOR);
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

