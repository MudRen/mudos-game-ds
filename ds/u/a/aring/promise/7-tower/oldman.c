#include <ansi.h>
inherit NPC;

void create()
{
  set_name("�Ѫ�", ({ "oldman" }) );
  set("gender", "�k��" );
  set("long",@LONG

���g�b�Z�L�W���ۤ@�u���a�A�H�ټC�P���դ����A�������򦹮�
�|�����p�������z�A�礣�ۧ����㪺�A�Q�����ۤ����H��������
�a�C

LONG
);
  set("age",61);
  set("level",1);
  set("race","human");
  set("chat_chance", 20);
  set("chat_msg", ({
"�Ѫ̤������Į�A���G���ۻ����������ơC\n",
(: command("stare") :),
}));
  set("talk_reply","�o��B�͡A�Q���Dԣ�лP�ڥ��(Say)�I\n");
  setup();
  add_money("coin",2000+random(1000));
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
  object player = this_player();
  if( !userp(me) ) return;
  if( me == this_object() ) return;

  if(strsrch(str,"����") != -1)
  {
    command("hmm");
    command("say ���ǧڤ@�ɤj�N�A�Ѧb�L�⤤�C");
    command("sigh");
  }
  if(strsrch(str,"�L") !=-1)
  {
    command("say �L�H���ӥL�A�O�ھԱѪ����ӤH�H");
    
  }
  if(strsrch(str,"�O��") != -1)
  {
    command("say �L�N�O���𪺶�D�A�H�٬��������ݦ�");
    command("say ��~�n���O�ڤӤj�N�A�Ӭݻ��L����O�A�ڤ]���|���o�p�����U���C");
    command("say �ץͳQ���b����̡C");
    command("say �o��B�͡A�A�@�N���ڦ��ܡH");
  }
  if(strsrch(str,"�@�N") != -1)
  {
    command("say ���ڵ��A��D��ܡA�Ĥ@���F�����ڸѲ�A�ĤG�ϧڥX�h�I");
    command("say �p�G�A��ܫe�̡A�{�b�N�ʤ�a(kill oldman)�C");
    command("say �խY�O��̡A���ڦb���a���A�A���K���ڨ��o�w�Q����Y�I�I");
    
  }
  if(strsrch(str,"�w�Q����Y") != -1)
  {
    command("say �o�ӦѸ餣���n�T�ڡA�ٹG�ڦY�U���r�ġI");
    command("say ť���O�n�b�A�@�ɤ@�˪��Ī��A�~��Ѭr�C");
    command("say �֡I�ڦb�o�൥�A�A�֥h�a�I");
    command("say ���F��F�ڪ��߷N�A�ڹB�δݦs�����O�A�e�A�즹�ȪŶ��̤����I�I");
    message_vision(HIW"\n�u���Ѫ̹B�_���O�A���F�@�x�µ�$N�h�A$N�����L�ܡI�I"NOR);
    player->move(__DIR__"4f_7");
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
     message("world:world1:vision","\n"HIY"�i�����P�ֳ��j�G"HIM"�Q�c���j��"+ob->query("name")+"�]�����Ѫ̡A���G�Q�Ѫ̪�� ��z�����ŤF�I�I\n\n"NOR,users());
           ob->die();
                     ::die();
        return;
}

