#include <ansi.h>
#include <command.h>
inherit NPC;
int do_divorce2(string index);
object ppl2, ppl1;

void create()
{
  set_name(HIM"�����ΤH"NOR, ({"pretty girl","girl"} ));
  set("gender", "�k��" );
  set("age", 18);
  set("long",@LONG
(buy house for �H)
LONG
);
  set("chat_chance",10);
  set("chat_msg",({
  (: command,"say �ӳ�~~������, �Цa���j�U�^��~~" :),
(: command,"giggle" :),
(: command,"say �j�a���n�s�Ǥ��ʲ��n�L�~!"  :),
(: command,"come"  :),
     }));
  set("level",1);
  set("attitude", "friendly");
  set("no_cast",1);
  set("no_kill",1);
  setup();
}

void init()
{
  seteuid(getuid(environment()));
  if(!userp(this_player())) return;
  add_action("do_buy","buy");
  add_action("do_yes",({"y"}));
  add_action("do_yes",({"yes"}));
  add_action("do_no",({"no"}));
  add_action("do_name",({"name"}) );
}
int do_buy(string str)
{
  object target, temp, ob = this_object(), me = this_player();
  if(str != "house") return notify_fail("�B��..�A�Q�Rԣ�F���?\n");
  if(query("divorcing")) return notify_fail("�o���G���b��.\n");

  message_vision(HIW"$N�V���a���G�ڷQ�R�@�ɩФl��Honey�L�V��...@@\n",me);
  if(me->query("bank/past") < 500000)
  {
    command("smile");
    command("say �@�ɩФl��50�������@@");
    return 1;
  }
  target = me->query("marry_id");
  if(!target)
  {
    command("peer");
    command("say Sorry...Did you have marry mate??");
    return 1;
  }
  if(userp(target) && environment(target) == environment(ob))
  {
    ppl1 = me;
    ppl2 = target; 
    set("divorcing",1);
    command("hmm");
    call_out("do_divorce1",3);
    return 1;
  }

  command("say �B��..�A��ı�o�o�بƭn���x�D��Q���P�N��?");
  command("snicker");
  return 1;
}

void do_divorce1()
{
  object ob = this_object();
  string index;

  if(environment(ppl1) != environment(ob))
  {
    command("flop");
    command("say ���D���]���{�H");
    delete("divorcing");
    delete("asking");
    return;
  }
  if(environment(ppl2) != environment(ob))
  {
    command("??");
    command("say �B��, �A����Q�ǡH");
    delete("divorcing");
    delete("asking");
    return;
  }
  command("smile "+ppl2->query("id"));
  command("say �z����Q�Q�n�R�@�ɩФl...�z�N�U�p��z�H");
  tell_object(ppl2,"�zHoney�ӽЩФl�@�ɡA�аݧA�P�N�ܡH [yes/no]\n"NOR);
  set("asking",1);
  return;
}
int do_yes()
{
  if(this_player() == ppl2 && query("asking"))
  {
    do_divorce2("y");
    return 1;
  }
  return 0;
}

int do_no()
{
  if(this_player() == ppl2 && query("asking"))
  {
    do_divorce2("n");
    return 1;
  }
  return 0;
}
int do_name(string id)
{
  if(this_player() == ppl1 && query("asking2"))
  { 
   if(file_size("/open/world1/kkeenn/marry/house/"+id+".c")>0) 
      return notify_fail("Sorry...�o�ӢעҤw�g���H�ιL�F...\n");
    ppl1->set("marryhouse",id);
    ppl2->set("marryhouse",id);
    write_file("/open/world1/kkeenn/marry/house/" + id + ".c", @ROOM_CODE
inherit ROOM;
void create()
{
        set("short", "�R����");
        set("long", "�o�O�@���z�Ѫ��p�Τl�C\n");
        setup();
        replace_program(ROOM);
}
ROOM_CODE
        );
    delete("asking2");    
    return 1;
  }
  return 0;
}
int do_divorce2(string index)
{
  object ob = this_object();
  object obj1,obj2;
  string marryhouse;
  if(index == "y")
  {
    message_vision(HIR"\n[$N��������: �u���ܡI�ڤ��i��Ϲ諸��~~]\n\n"NOR,ppl2);
    command("say �Ӧn�F�I���N������50�������I");
    if(ppl1->query("bank/past") < 500000)
    {
      command("say ������ӽжO����....");
      command("flop");
      command("ack");
      command("say ��ӬO�a���J?! ���p�j�ݨ����F�A�J�M�p���o��Ʊ��N��F�a�C");
      delete("divorcing");
      delete("asking");
      return 1;
    }
    if(environment(ppl1) != environment(ob))
    {
      command("flop");
      command("say ���D�]�F�A�o��Ʊ��N��S���L�a�C");
      delete("divorcing");
      delete("asking");
      return 1;
    }
    delete("divorcing");
    delete("asking");
    set("asking2",1);
    tell_object(ppl1,"�п�J�@��id[name id]\n"NOR);  
    return 1;
  }
  message_vision(HIC"\n[$N��M���n�F�n�Y]\n\n"NOR,ppl2);
  command("say ���H�z����Q���P�N���A�A���٬O���^�h�Ӷq�n�F...");
  delete("divorcing");
  delete("asking");
  return 1;
}
void reset()
{
  delete("divorcing");
  delete("asking");
  delete("asking2");
  command("say �A�Ӫ������A���Ѥ����A�Q���B���ѶX���C");
}
