#include <ansi.h>
inherit NPC;

int quest();

void create()
{
  set_name("���C�C", ({ "grandmother yan","yan" }) );
  set("gender", "�k��" );
  set("long",@LONG
�O�ݦo�ѤF�A�o�@����i�O�@�y���ǡA�i�����ť�O�j�h
����Ƴ��O���M�F�C
LONG
);      
  set("age",95);
  set("level",5);
  set("race","human");

  set("chat_chance", 20);
  set("chat_msg", ({
"���C�C��M�^�Y���F�A�@���C\n",
(: command("say ��..��... ��..��...") :),
(: quest :),
}));

  set("chat_chance_combat", 50 );        
  set("chat_msg_combat", ({
(: command("help!") :),
}) );
  set("talk_reply","�p�G�A�P�ڥ�� <say> �|�o�{�N�Q���쪺������I\n");
  setup();
  set("mirror_number",3);
  call_out("re_quest",900);
}

void init()
{
  add_action("do_no_ask","ask");
  add_action("do_shout","shout");
}

int do_no_ask()
{
  write("�Х� say <��ͪ��覡> �Ө��o�һݱ����C\n");
  return 1;
}

int do_shout(string str)
{
  if(!str) str = "...";
  if(strsrch(str,"��") !=-1)
    command("say �@��˻s������^���r�A�֥h���ڧ�ӡC");
  if(strsrch(str,"�E��") !=-1)
  {
    message_vision(HIR"$N�b$n������j�q: "+str+"\n"NOR,this_player(),this_object());
    command("say �ڡA��ڡA�E�����ɶ���աC");
    if(query("item_give")) return 0;
    new(__DIR__"obj/obj20")->move(this_object());
    command("give " +this_player()->query("id")+ " rice ball");
    this_object()->set("item_give",1);
    return 1;
  }
  return 0;
}

int quest()
{
  object ob = this_object();

  if(ob->query_temp("pass_quest"))
    message_vision("$N��M�^�Y�S���F�A�@���C\n",ob);
  else command("say �֮��F�ڪ��^���ڡH����A�Ѱ��Y�����ΤF�A�S�^�������o�C");
  return 1;
}

void relay_say(object me, string str)
{
  if( !userp(me) ) return;
  if( me == this_object() ) return;
  switch(random(3))
  {
    case 0 : command("say �ڡ��H����H");
             break;
    case 1 : command("say �ڡH�A��ԣ�r�H");
             break;
    case 2 : command("say ������H�E���H");
             break;
  }
  return;
}

int accept_object(object who, object ob)
{
  if( ob->query_amount() > 0 )
  {
    message_vision("$N���X"+chinese_number(ob->query_amount())+"�T"+ob->name(1)+"("+ob->query("id")+")��$n�C\n",who,this_object());
    command("say �����H"+ob->name(1)+"�H�o�Yԣ�J�|���H");
    call_out("no_give_money",1,who,ob,ob->query_amount());
    return 1;
  }
  if(ob->query("id") != "bamboo stick" )
  {
    command("?");
    write("["+this_object()->name(1)+"��"+ob->name(1)+"�ä��P����]\n");
    return notify_fail("");
  }
  if(this_object()->query_temp("pass_quest"))
  {
    command("say �n�n�n�A�~���H�A�ڦѤH�a�N���U�F�C");
    return 1;
  }
  call_out("wield_temp",2,ob,0);
  command("say ���r�A�A���ڪ��^���F�ܡH�n�n�A�o�ӪF�赹�A�a�C");
  new(__DIR__"obj/obj15")->move(this_object());
  command("give " +who->query("id")+ " mirror");
  this_object()->set_temp("pass_quest",1);
  return 1;
}

void wield_temp(object ob, int index)
{
  if(!this_object()) return;
  switch(index)
  {
    case 0 : command("wield stick");
             break;
    case 1 : command("hmm");
             break;
    case 2 : command("unwield stick");
             break;
    case 3 : tell_room(environment(this_object()),"���C�C���^������̭��h�F�C\n");
             destruct(ob);
             break;
  }
  if(is_fighting())
  {
    remove_call_out("wield_temp");
    ob->set_temp("broken",9);
    return;
  }
  else
  {
    index++;
    if(index<4) call_out("wield_temp",2,ob,index);
  }
  return;
}

int re_quest()
{
  this_object()->delete_temp("pass_quest");
  this_object()->delete_temp("item_give");
  call_out("re_quest",900);
  return 1;
}

void no_give_money(object who, object ob, int index)
{
  command("give " +who->query("id")+ " " +index+ " " +ob->query("id"));
}
