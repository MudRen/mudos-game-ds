#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�u��",({ "love guard","guard" }));
        set("long","�@��������@���u�áC\n");
        set("level",20);
        set("gender","�k��");
        set("class1","������");
        set("title",HIM"�m�������n"NOR);
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
        write( name() + "�N�A�d�F�U�ӡC\n");
      command("grin");
           say("�u�û��D�G"HIR"�n�����H���ݰݧڪ��@�a�I\n"NOR);
        return 1;
}

