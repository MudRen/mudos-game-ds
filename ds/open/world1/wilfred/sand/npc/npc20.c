#include <ansi.h>
#include <path.h>

inherit NPC;

void create()
{
  set_name(YEL"���F��"NOR, ({ "desert robber","robber" }) );
  set("gender", "�k��" );
  set("long",@LONG
�o�O����W�c�W�L���������ССy���F���z�����o�C
LONG
);
  set("age",25);
  set("level",10);
set("exp",3000+random(1000));
  set("race","human");
  set_skill("dodge",30);
  set_skill("parry",20);
  set("chat_chance", 30);
  set("chat_msg", ({
(: command("say �֧����X�ӡI�I�I") :),
(: command("say �L�����A�n���n�R�H�I") :),
}));

  set("chat_chance_combat", 50 );        
  set("chat_msg_combat", ({
(: command("say ��ڧ@��H�ھ�... �A���n�H���A�i�H�w�������X�o�̡I") :),
}) );
  setup();
  add_money("coin",500);
  carry_object(__DIR__"eq/eq10")->wear();
  carry_object(__DIR__"wp/wp5")->wield();
//   call_out("loop",600);
}

void init()
{
  ::init();
  add_action("do_guard","go");
}


int do_guard(string arg)
{
  if(!this_player()->visible(this_object())) return 0;
  if(!this_player()->query_temp("robber_pass"))
  {
    command("say �n�q�����L�A�d�U�R���] !!");
    return 1;
  }
  this_player()->delete_temp("robber_pass");
  return 0;
}

void die()
{
   object me;
  object env = load_object(WD_PAST+"sand/room37");
   if( !me = query_temp("last_damage_from") )
   me = this_player(1);
   if( !me )
   {
     ::die();
     return;
   }
//7     env->start_robber();    // ���}�o
 command("tchat ... "+me->name(1)+"..�A...�Ѥj�|���ڳ�����....");  // ���}�o^^
  ::die();
  return;
}

int loop()
{
  object env = load_object(WD_PAST+"sand/room37");
  object ob = this_object();

  return 1;  // �����۰ʶ}��, �t�~�����]���|�}��
  if(!ob) return 1;
  if(random(4))
  {
    remove_call_out("loop");
    call_out("loop",600);
    return 1;
  }

  command("say �ɭԨ�F�A�ӳq���Ѥj�@�n�C");
  command("hehe");
  message_vision("$N�榣���^��s��̤F�C\n",ob);
  env->start_robber();
  destruct(ob);
  return 1;
}

int accept_object(object who, object ob)
{
  if(ob->query("id") != "coin" )
  {
    command("say �ޡI�A�ڬO�a�A�֧����X�ӡI�I�I");
    return notify_fail("");
  }
  if ( ob->query_amount() < random(300)+300 )
  {
    command("say ���������I�����̤l�I");
    return notify_fail("");
  }
  who->set_temp("robber_pass",1);
    destruct(ob);
  command("say ��A�ѬۡC");
  command("say �n�A�A�i�H�u�F�I");
  return 1;
}

