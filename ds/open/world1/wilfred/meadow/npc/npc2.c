// �A��M�o�@�}���n�y�N�������������z  wilfred@DS
#include <ansi.h>
inherit NPC;

void create()
{
  set_name("���դh", ({ "cow master","master" }) );
  set("gender", "�k��" );
  set("long",@LONG
�y���դh�z�A���W�J���A�ۤp�P��쬰��A�L�����~���ͬ��A�着
�������߱o�C�ƤQ�~�p�@��A�����B����A�o�q�Ӥ��L�ݪZ�L����
�A�񨭭쳥���A�����ۼ֡C�J���~�O�C�Q�A�վv�a�a�A����������
�A���鰷���A�⨬�����A�۬O����`�����\�׬���������~���C��
��H�κz�_���H����ܦ��߷��j���Ůt�A�U�ڬҦV����Ѿǲߦ��
�S�������\�ߪk�A�J����`�P�䱵Ĳ�A�۬O�Ǩ줣�֮���B�檺�n
���A���M���}�\�ҥ��o�W�a�Ǳ¡A���ȵۤ@�M�ۦ�N���X��������
�k�A�H�Τ��\���׬��A��i�C�Z�L�n�⤧�y�C
LONG
);
  set("age",72);
  set("level",40);
  set("race","human");
  set("chat_chance", 20);
  set("chat_msg", ({
(: command("exert momo-ken") :),
"���դh�ݵۻ���A���Y�L�١A���G���Ƿдo�C\n",
(: command("hmm") :),
}));

  set_skill("momo-ken",100);
  set_skill("unarmed",80);
  set_skill("parry",40);
  set_skill("dodge",30);
  map_skill("unarmed","momo-ken");
  set("Merits/wit",2);
  set("talk_reply","�p�G�A�P�ڥ�� <say> �|�o�{�N�Q���쪺������I\n");
  setup();
  set_living_name("cow_master");
  add_money("gold", 5 );
  carry_object(__DIR__"eq/eq1")->wear();
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
  object ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;

  if(strsrch(str,"����") != -1)
  {
    command("hmm");
    command("say �ڤ@�ͪ����A�ƻ�����������������L�A�䤣�P�~�ت��u�I�i���O�U�ճӳ��C");
    command("say ���������@�H�A�A�X�z�_����ԡA�ҥH�o�����W�񪪪����O�����C");
  }
  if(strsrch(str,"����") !=-1 || strsrch(str,"�дo") != -1)
  {
    command("say �کw���n��P�k�s���@�嬺���H�ƭx�ΡA�������ͩʤ��ߨ�����A�]�������������u�@�`�O�ڷдo�C");
    command("say �p�G�A�����ڻ����������A����b�O�_�䪺�]��̡A�ۦ��S�¡C");
    command("say �ܩ��k��.....");
  }
  if(strsrch(str,"��k") != -1)
  {
    command("say ��.... ��k����²��C");
    command("say ����Ԩ���w��V�h�A�Ҧp(pull east)�A�Ԩ�]��̦A��b�W�l�W(lock_up)");
    command("say �o�˴N��F�C");
  }

  return;
}

void die()
{
   object ob;
   if( !ob = query_temp("last_damage_from") )
   ob = this_player(1);
   if( !ob )
   {
     ::die();
     return;
   }

   message("world:world1:vision",
HIG"\n�i�p�D�����j�W���z�_���y���դh�z�J���Q"+ob->name(1)+"�����F�C\n\n"NOR,users());

   tell_object(ob,HIW"[�A�o���B�~�� 1 �I�n��]\n"NOR);
   ob->add("popularity",1);
   ::die();
   return;
}


