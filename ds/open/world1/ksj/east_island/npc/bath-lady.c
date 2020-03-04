#include <path.h>
inherit NPC;

void create()
{
  set_name("����p�j" , ({ "bath lady","lady" }));
  set("long",@LONG
�b���ΪA�Ȫ��@��~�����p�j�A��۲H�Ŧ⪺�M�A�A�b�d�x�e�۩I��
�ȤH�A�Y�Q�~�ӷŬu�νw���ߡA�u�n�I�ǿ�(pay)�N��i�h�F�C
LONG);
  set("chat_chance",9);
  set("chat_msg",({
      "����p�j��A���`���D�G�z�n�A�o��ȤH�Q�w��(spa)�ܡH\n",
     (: command,"smile" :),
     (: command,"say �w�Ӵ��i�H�Ѱ��h�ҳ��" :),
     (: command,"say �����Ϊ��Ŭu���������h�]���\\�ĳ��" :),
     }));
  set("inquiry",([
      "�w��" : "�w��(spa)�@�� 300 �����I\n",
     ]));
  set("no_fight",1);
  setup();
}

void init()
{
  object ob;
  ::init();
  if( interactive(ob = this_player()) && !is_fighting() ) 
  {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }
  add_action("do_pay","pay");
}

void greeting(object ob)
{
  if( !ob || environment(ob) != environment() ) return;
  switch( random(2) )
  {
    case 0:
      say( "����p�j�µۧA����V���`���D�G�w����{�C\n");
      break;
    case 1:
      say( "����p�j��A���D�G�ȤH�Q�w�ӵΪA�����ܡH\n");
      break;
  }
}

int do_pay(string arg)
{
  object me,ob;
  string c;
  me = this_player();
  ob = this_object();

  if( !arg || sscanf(arg,"for %s",c)!=1 )
    return notify_fail("����p�j�ôb�a���D�G�ȤH�O�n�w���ܡH(pay for spa)\n");

  switch(c)
  {
    case "spa":
      if( !me->can_afford(300) )
        return notify_fail("�A���W����������C(300���)\n");
      me->receive_money(-300);
      me->add_temp("bathe",1);
      message_vision("$N�I���F$n�w���@�����O�ΡA�`�@�T�ʤ���C\n",me,ob);
      command("nod "+me->query("id"));
      command("say �o��ȤH�Щ��̭���(enter)");
      break;
    default:
      write("�z�O�n�w��(spa)�ܡH\n");
      break;
  }
  return 1;
}
