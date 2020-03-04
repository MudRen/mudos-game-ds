#include <ansi.h>
inherit NPC;

int quest();

void create()
{
  set_name("�i�y��", ({ "hunter chung","chung" }) );
  set("gender", "�k��" );
  set("long",@LONG
�Y�칡�ȴ̪�������A���H���n�A�|���ҥS�̡C
LONG
);      
  set("age",32);
  set("level",25);
  set("race","human");

  set("chat_chance", 20);
  set("chat_msg", ({
"�i�y�᥿���۩۩I���̪��ȤH�C\n",
(: command("say �ͩ��������Ҭ����H�˦ۥX�~���y�ӨӡA�s�A�����I�������I") :),
(: quest :),
}));

  set("chat_chance_combat", 50 );        
  set("chat_msg_combat", ({
(: command("say �ܡI���ѤƤ餧�U�������T�I�ǩR�ӡI") :),
}) );
  set("talk_reply","�p�G�A�P�ڥ�� <say> �|�o�{�N�Q���쪺������I\n");
  setup();
  carry_object(__DIR__"eq/eq9")->wear();
  set("mirror_number",4);
  call_out("re_quest",900);
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

int quest()
{
  object ob = this_object();

  if(ob->query_temp("pass_quest"))
    command("say �ש�p�@�H�v�F�A�������A���M���s�ޤ��O�ۤv�y�쪺�A���`��O��F�ت��F�C\n");
  else command("say �ڥͥ����ѥu���@�ӡA�N�O�y������s�ޡA���I");
  return 1;
}

void relay_say(object me, string str)
{
  object ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;
  if(strsrch(str,"���s��") != -1)
  {
    command("sigh");
    command("say ���s�ަb���F���W�~���A�������s�ޥͩʾ��ӡA�C���H�a��K�k���L�ܡC");
    command("say �ӥB���F���W�s����A����j�������A���I");
  }
  return;
}

int accept_object(object who, object ob)
{
  if( ob->query_amount() > 0 )
  {
    message_vision("$N���X"+chinese_number(ob->query_amount())+"�T"+ob->name(1)+"("+ob->query("id")+")��$n�C\n",who,this_object());
    command("say ��ڬO�S�̴N�O�e�o�Ҥ��l�����N�A"+ob->name(1)+"�A���^�h�C");
    call_out("no_give_money",1,who,ob,ob->query_amount());
    return 1;
  }
  if( ob->query("victim_name") == RED"���s��"NOR )
  {
    if(this_object()->query_temp("pass_quest"))
    {
      command("say �h�§A�F�A�p���S����n�������F��A�����N���ܡA�b�o�̦Y�Ӷ��A���a�C");
      return 1;
    }
    command("really " +who->query("id"));
    command("say �G�u�O���s�ް� ... �ӷP�¤F�A�ڦ����o�����A�o���e�A��@�����a�C");
    new(__DIR__"obj/obj15")->move(this_object());
    command("give " +who->query("id")+ " mirror");
    this_object()->set_temp("pass_quest",1);
    return 1;
  }
  command("say ��ڬO�S�̴N�O�e�o�Ҥ��l�����N�A"+ob->query("name")+"�A���^�h�C");
  write("["+this_object()->query("name")+"��"+ob->name(1)+"�ä��P����]\n");
  return notify_fail("");
}

int re_quest()
{
  this_object()->delete_temp("pass_quest");
  this_object()->delete_temp("item_give");
  this_object()->delete_temp("item_give_who");
  call_out("re_quest",900);
  return 1;
}

void no_give_money(object who, object ob, int index)
{
  command("give " +who->query("id")+ " " +index+ " " +ob->query("id"));
}
