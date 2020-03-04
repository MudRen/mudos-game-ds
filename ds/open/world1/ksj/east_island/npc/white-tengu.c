#include <ansi.h>
#include <combat.h>
inherit NPC;

mapping *combat_action = ({
        ([  "action":       "$N�k��@���A�@�����u���۪��������Y��V$n��$l",
                "attact_type":  "sou",
                "damage_type":  "���F�ж�",
        ]),
        ([  "action":       "$N���|����A�q�|���K��̪ŭ��ӵL�ƧQ�bŧ�V$n",
                "attact_type":  "sou",
                "damage_type":  "���F�ж�",
        ]),
        ([  "action":       "$N�R�X�@�ΥշϾ����@�����j���զ��x�A�r�M��V$n",
                "attact_type":  "sou",
                "damage_type":  "���F�ж�",
        ]),
});

mapping query_action()
{
  return combat_action[random(sizeof(combat_action))];
}

void create()
{
  set_name(HIW"�դѪ�"NOR, ({"white tengu","tengu"}) );
  set("long",@LONG
��O�S�j���T��Ѫ����@�A�թ�ϥΤۨ��N�A�b�Ѫ������a��Ȧb��
�Ѫ����U�C
LONG);
  set("race", "�H��");
  set("unit","��");
  set("age",80);
  set("attitude", "aggressive");
  set("gender", "�k��" );
  set("level",50);
  set("tengu",1);
  set("title",HIW"�T��Ѫ�"NOR); 
  set_skill("unarmed",100);
  set_skill("fork",100);
  set_skill("dodge",100);
  set_skill("parry",100);
  set_temp("apply/hit",30);
  set_temp("apply/dodge",30);
  add("addition_armor",150);
  set_temp("float",1);
  setup();
  set("default_actions", (: call_other, __FILE__, "query_action" :));
  set("actions", (: call_other, __FILE__, "query_action" :));
  set_living_name("tengu-war-tengu");
  carry_object(__DIR__"eq/cloud-halbert")->wield();
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if( this_player()->query("tengu-enemy") ) this_object()->kill_ob(this_player());
  if(userp(this_player())) this_object()->kill_ob(this_player());
}

int special_attack(object me, object target, int hitchance)
{
  object z;
  int sim,j;
  sim=random(3)+1;
  if(!me) return 0;
  if(me->is_busy()) return 0;
  if( me->query_temp("wait_to_summon") ) return 0;

  if( !me->query_temp("weapon") && objectp(z=present("cloud halbert",me)) )
    command("wield halbert");

  if( !random(13) )
  {
    me->start_busy(1);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
    COMBAT_D->report_statue(target);
    return 1;
  }
  else if( !random(9) )
  {
    me->start_busy(2);
    message_vision("\n$N"HIW"���W�_�X�j�q�����A���������X�{"+sim+"���դѪ��I\n"NOR,me);
    for(j=0;j<sim;j++)
    {
      new(__DIR__"sim-tengu")->move(environment(me));
    }
    set_temp("wait_to_summon",1);
    call_out("delay",20);
    return 1;
  }
  return 0;
}

void delay()
{
  delete_temp("wait_to_summon");
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
  ob->add("popularity",3);      
  tell_object(ob,HIG"�A�o�� 3 �I�n��C"NOR);
  ::die();
  return;
}
