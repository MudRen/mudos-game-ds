#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�M�I�D��" ,({ "taoist" }) );
        set("level",15);
         set("race","�H��");
         set("gender","�k��");
        set("age", 35);
        set("long", "�L�O�M���������]���D���A�L��A�w�Q��V���A����C\n");
        set_skill("dodge",40);
            set_skill("sword",30);
        set_skill("parry",20);
        set("evil",0);
        set("talk_reply","�A�����������a�v�������ܡH\n");
        set("inquiry/�a�v","�a�v�T�Ӥ�e�]�ƥ~�X�A�ܤ����������A�����\n");
        set("limbs", ({ "�Y��", "����", "���}", "�k�}", "���" }) );
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 10);
        set("chat_chance", 4);
        set("chat_msg",({
               "�M�I�D�����D�G���A�ѱ����L�͡A���p�����F�`�A�s�ڤ]�S��...\n"
        }) );
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
                (:command("exert hungchen-sword"):),
                "�M�I�D���ܹD�G��l�I�I�I�I�䦺�H�H�H\n",
                "�M�I�D�����D�G���̵L�޵L���A�N���}��p��H\n",
        }) );
        setup();
}
int accept_object(object who,object ob)
{
  object me;
  object pike;
  me=this_player();
  if(ob->name()!="��")
  {
if(ob->name()!="�Ѯv���C")
{
      command("eh");
      command("say �ڤ����n�o�تF��C");
      return 0;
     }
else {
      me->set_temp("GETwp/feipike",1);
      command("say �x�I�I�o���O���v���_�C�ܡI�I");
      say(YEL"�M�I�D��Ÿ�ݵ��n���D�G���v�_�C�q���������A���D������D���\n"NOR);
  command("fear");
  say(YEL "�M�I�D�����G�o��" + RANK_D->query_respect(ob) + "��i�D�ڮ��v�b���ܡH\n" NOR);
  return 1;
}
  }
  else {
    if(me->query_temp("GETwp/feipike")>0)
    {
      say("�M�I�D���J�Ӫ��ݤF�ݳo�i�ȡC\n");
      say(YEL"�M�I�D���j�s�G�ڡ�㮦�v�K���v�L�K�C\n"NOR);
      command("cry");
      say(YEL"�M�I�D����몺�D�G�o�Ӹ騸�СA��I�I�I�𦭭n���v�����C\n"NOR);
      command("sob");
      me->delete_temp("GETwp");
      say(YEL"�M�I�D�����G�o��" + RANK_D->query_respect(ob) + "�e�X��ڥs�H���F�@����j�A�o���j�i�O�κ����y�Ӧ��A�ڳo�N�e�A�a�C\n"NOR);
         message_vision("�M�I�D����$N�@�⭸�_�j�C\n",me);
         pike=new(__DIR__"wp/pike");
         pike->move(who);
         command("bow");
       return 1;
    }
  }
}
