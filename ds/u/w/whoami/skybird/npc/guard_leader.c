#include <ansi.h>
inherit NPC;
void create()
{
  set_name("���Q",({"wang bar","wang","bar"}));
  set("long",@LONG
�L�N�O���F�q���u�ê��ⶤ�F, ���H�۷���, �q�`������
�M�H�ʤ�, ���L�ѩ󥭤������ȤӹL�Q�D, ť�����������e�F
�L�@�ӥ~��....
LONG
    );
  set("attitude", "peaceful");
  set("age",32);
  set("gender","�k��");
  set("level",31);
  set_skill("blade", 60);
  setup();
 carry_object(__DIR__"eq/cloth")->wear();
 carry_object(__DIR__"eq/soldier_boots")->wear();
 carry_object(__DIR__"eq/fur_waist")->wear();
 carry_object(__DIR__"eq/cloud_ring")->wear();
 carry_object(__DIR__"eq/steel_blade")->wield();
carry_object(__DIR__"obj/wang_mark");
carry_object(__DIR__"obj/paper");
}

void relay_say(object me, string str)
{
  object ob = this_object();
  if(strsrch(str,"���K���x") !=-1)
  {
    message_vision(YEL"$n�h�F�@�h, �H�Y�j��D: �p��䦺 !!�C\n"NOR,me,ob);
   message_vision(YEL"$n��몺��:�p��N���n���ڧ��A���a....�C\n"NOR,me,ob);
 command("follow "+me->query("id") );
  }
  
}