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
  set("no_kill",1);
  set("no_fight",1);
  set("no_cast",1);
  setup();
}

void relay_say(object me, string str)
{
  object ob = this_object();
  if(strsrch(str,"���K���x") !=-1)
  {
      message_vision(YEL"$n�h�F�@�h, �H�Y�j��D: �p��䦺 !!�C\n"NOR,me,ob);
      ob->kill_ob(me);
  }
  else
  {
    switch(random(8))
    {
      case 1 : command("hmm");  break;
      case 2 : command("think");   break;
      case 3 : command("say �b�o�̳�I����? �ֺu!");  break;
      case 2 : command("say �����٤��ֺu!");   break;
  }
  }
  return 1;
}
