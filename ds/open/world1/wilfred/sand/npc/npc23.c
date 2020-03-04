#include <ansi.h>
#include <path.h>

inherit NPC;

string *go_temp = ({
"south","east","south","eastdown","east","east","south",
"east","east","east","east","east","east","east","east","east",
"south","east",
});

int do_super();

void create()
{
  set_name("���F���Y�Y", ({ "desert robber","robber" }) );
  set("gender", "�k��" );
  set("long",@LONG
�o�O����W�c�W�L���������ССy���F���z���Ѥj�C
LONG
);
  set("age",35);
  set("level",23+random(3));
set("exp",10000+random(2000));
  set("race","human");
  set("chat_chance_combat", 50 );
  set("chat_msg_combat", ({
(: command("cow") :),
}) );
  setup();
  set_living_name("robber_war");
  call_out("do_shout",1);
}

void do_shout()
{
  remove_call_out("do_shout");
  command("tchat �S�̡̭I���̫e���ɿ����T�h�a�I�I");
  command("tchat* wahaha");
  call_out("go",1,0);
  return;
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
  HIY"���F���Y�Y�j���D�G�y�������A�h�¦U��ѷݪ��Ȥl�I�I���̫�|�����F�I�z\n",users());
  call_out("robber_dest",2,ob); // 2003.4.14 �s�W  by ksj
  env->get_money();
  destruct(ob);
  return;
}

// 2003.4.14 �s�W  by ksj
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

  if(index == 7)
  {
    call_out("action1",2);
    call_out("action2",5);
    call_out("go",7,++index);
    return 1;
  }
  call_out("go",random(3)+1,++index);
  return 1;
}

int action1()
{
  object ob = this_object();

  if(!environment(ob)) return 1;
  command("say ������L�A�Ѥl��A���F�I�S�̡̭A�A�̥����A�o�̵��ڨӾסI�I");
  message_vision(HIW"\n���H���D�G �O�I�I�I\n\n"NOR,ob);
  return 1;
}

int action2()
{
  object ob = this_object();
  if(!environment(ob)) return 1;
  if(!present("boundary guard",environment(ob)))
    return 1;
  else
  {
    command("say �ݨӦѤl�����I�\\�ҡA�A�̭ˬO��Ѥl��f�߬ݤF !!");
    do_super();
    return 1;
  }
}

int do_super()
{
  object ob = this_object(), *enemys;
  int i;

  ob->start_busy(0);
  new(__DIR__"wp/wp6")->move(ob);
  command("wield whip");

  message_vision(HIW"\n   $N"HIW"��ܤ@�n "HIR"�y�ۡI�I�I�I�I�z"HIW" �@�Y�p�ȳD��A�H�֯e�L�񪺳t�פ������H�I�I\n\n"NOR,ob);

  enemys = all_inventory(environment());
  for(i=0;i<sizeof(enemys);i++)
  {
    if(enemys[i] == ob || enemys[i]->query("id") == "desert robber") continue;
    if(userp(enemys[i]))
      message_vision(HIW"$N�j�Y�@��A���Ϋ��A�ϭӡy�K�O���z�\\�ҡA�b�����e�v���Z�������׹L�I�I\n"NOR,enemys[i]);
    else
    {
      message_vision("�@�Y����������$N�I�I$N���p�_�u�������뭸�h�I�I���۷ƥX�ƤQ�V�I�I�I "HIR"(" +(random(2000)+1000)+ ")\n"NOR,enemys[i]); // ���ֳ\msg by alick,�쥻�������q..obj ������
      enemys[i]->die();
    }
  }
  return 1;
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
HIY"\t���F���Y�Y�j�ۡG�i�c��" +ob->name(1)+ "�A���ٷ|�A�Ӫ��I�I\n"NOR,users());

   tell_object(ob,HIC"[�A�o���B�~�� "+(1 + ob->query_temp("quest/sandwarp")/2)+" �I�n��]\n"NOR);
   ob->add("popularity",( 1 + ob->query_temp("quest/sandwarp")/2 ) );
   ob->delete_temp("quest/sandwarp");
   ::die();
   return;
}
