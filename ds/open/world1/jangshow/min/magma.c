#include <ansi.h>
inherit NPC;
void create()
{
  set_name(HIR"���]���H"NOR, ({"magma man","man","magma"}) );
  set("long",@LONG
�|���_�������߸̽ϥͥX�Ӫ����H�A�����O�j�j�A�b���ߦa��
�|�B�����ޡC
LONG
);
  set("race", "beast");
  set("unit","��");
  set("age",200);
  set("level",35);  
  set("attitude", "aggressive"); 
  set("evil",2000);
  set("limbs", ({ "�Y��", "����","�ݳ�","��","�}","�I��" }) );
  set("verbs", ({ "bite","claw" }) );  
  set("chat_chance", 13);
  set("chat_msg",({  
  (:random_move():),
  "���]���H�����W�������d�۩���....\n",  
        }));
  setup();
  add_money("coin",1000);
} 
void init()
{       
        object ob;
        ::init();
        if( environment(this_player())->query("no_kill") ) return;
        if( environment(this_player())->query("no_fight") ) return;
        if(!this_object()->visible(this_player())) return;
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{ 
        //object me=this_player();
        if( random(3) ) return; // 1/3 ���v add by whoami 
        if( !ob || environment(ob) != environment() ) return; 
        {
                        message_vision(HIR"\n���]���H�ܹD�G���̨Ӫ��p�^�ءI���R�ӡI\n"+NOR,ob);
                        ob->receive_damage("hp",random(300)); //300�Ӱ��F �令random add by whoami 
                        this_object()->kill_object(environment(ob));
        }
}

