#include <ansi.h>

inherit NPC;
void create()
{
        set_name("�p��",({ "child" }) ); 
        set("long","�@�ө~��b�y�������p�ġA��ѼH�����֡A���L���G���۰�\n"
                   "�j���ڷQ�I\n");
        set("race","human");
        set("gender", "�k��");
        set("title", HIR"�y����"NOR);
        set("age",4+random(5));
        set("level",5+random(5));
        set("attitude","friendly");
        set_skill("dodge",15);
        set_skill("unarmed",15);
        set_skill("parry",15);
        set("chat_chance",20);
        set("chat_msg", ({
                          (:command("say �ڤ@�w�n���F�E���A�������l���^���I") :),
                          (:command("addoil child"):),
        }));

        setup();
        add_money("coin",200);           
        set("talk_reply","�p�G�A�P�ڥ�� <say> �|�o�{�N�Q���쪺������I\n");
}
void init()
{
  add_action("do_no_ask","ask");
}

int do_no_ask()
{
  write("�Х� say <��ͪ��覡> �Ө��o�һݱ����C\n");
  return 1;
}
void relay_say(object me, string str)
{
  if( !userp(me) ) return;
  if( me == this_object() ) return;
  if(strsrch(str,"�ڷQ") != -1)
  { 
    command("oh"); 
    command("say �ڪ��ڷQ�N�O����F�����E���I"); 
  }  
return;
}

