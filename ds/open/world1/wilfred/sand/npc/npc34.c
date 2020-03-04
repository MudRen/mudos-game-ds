#include <ansi.h>
inherit NPC;

int quest();

void create()
{
  set_name("�g�~�ȤH", ({ "traveler" }) );
  set("gender", "�k��" );
  set("long",@LONG
�o�O�@���۴��q���Ȧ�̡A�L���y����W�A�ݨӬO�g���F�C
LONG
);      
  set("age",22);
  set("level",1);
  set("race","human");

  set("chat_chance", 20);
  set("chat_msg", ({
"�ȤH�W�i���ݤF�ݤF�|�P�A�A����W���a�ϡC\n",
(: command("say �_�ǡA�����O���o�̨��S����...") :),
(: command("ack") :),
(: command("help!") :),
}));

  set("chat_chance_combat", 50 );
  set("chat_msg_combat", ({
(: command("help!") :),
}) );
  set("talk_reply","�ڰg���F�I�ϩR�ڡI�I�ϩR�ڡI�I�A��a�ڦ^���F��~�ܡ���\n");
  setup();
}

void init()
{
  object ob = this_object();
  object inv = environment(ob);
  if(inv->query("short") == "���F��~")
  {
    command("follow none");
    command("say �S .... �o�ϤF ... ");
    command("thank");

    if(!random(6))
    {
      command("say �ڦ��n��ƭn��A�ֳ��F�A�o�F��O�ڦb����W�ߨ쪺�A�ݨӮ��ȿ����A���A�a�C");
      message_vision(HIW"[$N��U�@�ӬY���~]\n"NOR,ob);
      new("/open/always/time-q/white_crystal")->move(inv);
    }

    message_vision("$N�榣�����}�F�C\n",ob);
    call_out("dest_temp",1);
  }
}

void relay_say(object me, string str)
{
  object ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;
  if(   strsrch(str,"�i") != -1 
     || strsrch(str,"��") != -1
     || strsrch(str,"��") != -1
     || strsrch(str,"�n") != -1
    )
  {
    command("say �A�n���ڶܡH�ַQ�ӿ�k�a!");
    return;
  }
  if(strsrch(str,"follow") != -1 && ( strsrch(str,"me") != -1 || strsrch(str,me->query("id")) != -1 ) )
  {
    call_out("do_follow",1,me);
    return;
  }
  if(strsrch(str,"��") != -1 && ( strsrch(str,"��") != -1 || strsrch(str,me->query("name")) != -1 ) )
  {
    call_out("do_follow",1,me);
    return;
  }
  return;
}

int do_follow(object me)
{
  command("thank");
  command("follow "+me->query("id"));
  return 1;
}

void dest_temp()
{
  destruct(this_object());
}
