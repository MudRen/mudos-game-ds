#include <ansi.h>
#include <path.h>

inherit NPC;

string *go_temp = ({
"south","east","south","eastdown","east","east","south",
"east","east","east","east","east","east","east","east","east",
"south","east",
});

void create()
{
  set_name("���F��", ({ "desert robber","robber" }) );
  set("gender", "�k��" );
  set("long",@LONG
�o�O����W�c�W�L���������ССy���F���z�����o�C
LONG
);
  set("age",26);
  set("level",15+random(3));
  set("exp",5000+random(1000));
  set("race","human");
  set_skill("dodge",50);
  set_skill("parry",40);
  set("chat_chance_combat", 50 );
  set("chat_msg_combat", ({
(: command("cow") :),
}) );
  setup();
  set_living_name("robber_war");
  carry_object(__DIR__"eq/eq12")->wear();
  carry_object(__DIR__"wp/wp3")->wield();
  call_out("go",1,0);
}

void init()
{
  object ob = this_object(), me = this_player();
  object env = load_object(WD_PAST+"sand/room37");

  if(userp(me)) command("say �u�}�I�O�׸��I�I");
  if( me->query("id") == "harn-tar-fu" )
  {
    command("hehe");
    command("say ������X�ӡI�I�ʧ@�֡I�I");
    call_out("robber",2,ob,env);
  }
}

void robber(object ob,object env)
{
  if(!ob) return;
  message_vision("�����ܧ֪��Q$N�~�T�@�šI�I\n",ob);
  message("world:world1:vision",
  HIY"���F��j���D�G�y�������A�h�¦U��ѷݪ��Ȥl�I�I���̫�|�����F�I�z\n"NOR,users());
  call_out("robber_dest",2,ob); // 2003.4.10 �s�W  by ksj
  env->get_money();
  destruct(ob);
  return;
}

// 2003.4.10 �s�W  by ksj
void robber_dest(object ob)
{
  destruct(ob);
}

int go(int index)
{
  object ob = this_object();
  if(!environment(ob)) return 1;
  if(index == sizeof(go_temp)) return 1;

  if(ob->is_busy())
  {
    call_out("go",1,index);
    return 1;
  }

  command(go_temp[index]);

  call_out("go",random(4)+3,++index);
  return 1;
}

void die()
{
   object ob;
   if( !ob = query_temp("last_damage_from") )
   ob = this_player(1);
   if( ob ) ob->add_temp("quest/sandwarp", 1);
   ::die();
   return;
}
