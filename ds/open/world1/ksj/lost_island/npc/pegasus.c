#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIC"����"NOR, ({"pegasus"}) );
  set("long",@LONG
�@�����F�@���զ���l���@���A���R���Ҽ˦��p�Ѱ��U�Z�C
LONG
);
  set("race", "beast");
  set("gender", "����");
  set("unit","��");
  set("age",10);
  set("level",27+random(2));
  set("title",HIW"  �_�~ "NOR);
  set("limbs", ({ "�Y��", "����","�e�}","��}","�ͻH" }) );
  set("verbs", ({ "bite","crash" }) );
  set("chat_chance", 20);
  set("chat_msg", ({
  (: random_move :),
  }));
  set("ridable",1); 
  setup();
}

int ride_before_action(object me)    
{
        int s = me->query("str");
        if( s<40 || !s )
        {
                message_vision("�ѩ�$N���O�q�����A�L�k����"+this_object()->name()+"�A�]�ӳQ"+this_object()->name()+"�q���I�W�L�F�U�ӡI\n",me);
                return 0;            
        }
        else 

        {
                message_vision("$N�ϥX�������Z�O�ǳƩ��A�o��"+this_object()->name()+"�C\n",me);
                return 1;            
        }
}

int ride_after_action(object me)    
{
        message_vision("$N�w�g�M�W�F"+this_object()->name()+"�C\n",me);
        set("chat_chance",0);
        return 1;                
}


int ride_off_action(object me)        
{
        message_vision("$N�w�g���}"+this_object()->name()+"�F�C\n",me);
        return 1;                    
}

