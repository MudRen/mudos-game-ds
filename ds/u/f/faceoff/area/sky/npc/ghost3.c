#include <ansi.h>
inherit NPC;
void create()
{
 set_name(HIR"�U���F��"NOR,({"guard"}));
 set("long",@LONG
�ڻ��o�O�Q�U�j�s�Щl����Y���A�Q�U�j�s���F�۸s�A
�Ӧp���L�b�Ѭɱo�쥿��A�u�@�ۯ���...
LONG
    );
 set("attitude", "peaceful");
 set("age",34);
 set("nickname",HIC"�V�P����"NOR);
 set("evil",-10);
 set("gender","�k��");
 set("level",40);
set("str",200);
set("con",200);
 set_skill("unarmed", 100);
 set("chat_chance",30);
 set("chat_msg", ({"�U���F�ۥ|�P���Ŷ����M�ҽk�F�_��....\n", 
        }) );
 setup();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

}

void greeting(object ob,object who)
{
      object me;
      me = this_player();
        if( !ob || environment(ob) != environment() ) return;
        {
             if(me->query_temp("bless") == 1)
           {
                        message_vision( "�U���F�ۧ���$N�ɡA$N���W������I�N�F�U���F�۪�Ĳ��...!!\n",me);
           }
           else
           {
                    message_vision( "�U���F�۹��$N���X�FĲ��......�C\n",me);
                        command("kill "+me->query("id"));
            }
                 }
}



