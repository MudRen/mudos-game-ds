#include <ansi.h>
inherit NPC;
void create()
{
 set_name(MAG"�߽�"NOR,({"guard"}));
 set("long",@LONG
�o�O�b�Q�U�j�s�ʦL�s�~�ɧ𥴯����}�`�����~�Ʀ�����z�A
�b�o�̥åû������@�õۥ��g���\�i�J�������I�J��....
LONG
    );
 set("attitude", "peaceful");
 set("age",34);
 set("nickname",HIC"�Ц]����"NOR);
 set("evil",-10);
 set("gender","�k��");
 set("level",20);
set("str",100);
set("con",200);
 set_skill("unarmed", 100);
 set("chat_chance",30);
 set("chat_msg", ({"�߽ó������§A�ݤF�@��.....\n", 
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
                        message_vision( "�߽ù�$N�@�F���w�諸��աC\n",me);
           }
           else
           {
                 message_vision( "�߽ó����ݵ�$N....�C\n",me);
                         command("kill "+me->query("id"));
            }
                 }
}



