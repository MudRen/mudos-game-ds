#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�O�W�̤l",({ "apprentice" }));
        set("long","�@��Ѥs���ǳƦ����p�̤l�C\n");
        set("level",10);
        set("gender","�k��");
        set("title",HIM"�m�������n"NOR);
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

