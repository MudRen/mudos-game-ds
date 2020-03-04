#include <ansi2.h>
#include <combat.h>
inherit NPC;
void normal_ai();

mapping *combat_action = ({
        ([  "action":       "$N�������_�A�H�Y�s�R�ۤ��ռ��V$n",
                "attact_type":  "bar",
                "damage_type":  "����",
        ]),
});

mapping query_action()
{
  return combat_action[random(sizeof(combat_action))];
}

void create()
{
  set_name(GRN"�K���j�D"RED"�D"HBK"�­�"NOR,({"orochi black head","black head","head","_BLACK_HEAD_"}) );
  set("long",@LONG
�K�Y�K���A���j���ߦ��p�K�y�s�p�P�K�Ӥs���@�몺���Ƥj�D���W��
���B�̡A������K�y�s���B�s���A�����w�ۨ���C�A�{�b�Ҭݨ쪺��
���O�K���j�D���K���Y���@�A�ާ@���O���¦�D���C
LONG
);
  set("race", "���~");    
  set("unit","��");
  set("age",2000);
  set("evil",200);
    set("attack_merits","bar");
  set("attitude", "aggressive");
  set("level",70);
  set("orochi",1);
  set("orochi_beast_3",1); 
  set("limbs", ({ "�B��","�|��","����","�Y��"}) ); 
  set("verbs", ({ "bite","crash"}) );     
  set("Merits/bar",14);
  set("Merits/bio",11);
  set("Merits/wit",5);
  set("Merits/tec",4);
  set("Merits/sou",5);
  add("addition_damage",80);
  add("addition_armor",240);
  add("addition_shield",50);
  set_temp("apply/hit",40);
  set("chat_chance", 30);
  set("chat_msg",({
     (: normal_ai() :),
     (: random_move :),
  }) );
  setup();
  set("default_actions", (: call_other, __FILE__, "query_action" :));
  set("actions", (: call_other, __FILE__, "query_action" :));
  set_living_name("_NPC_BLACK_HEAD_");
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if( this_player()->query_temp("invis")>2 ) return;
  if(userp(this_player()) ) this_object()->kill_ob(this_player());
  if( this_player()->query("orochi-enemy") ) this_object()->kill_ob(this_player());
}

void normal_ai()
{
  object me,target;
  me = this_object();
  target = this_player();
  if(me->is_busy()) return;
  if( me->query("hp") + 1000 < me->query("max_hp") )
  {
    message_vision("\n$N"HIG"�Ⲵ�L���A�a�b�����ǥ𮧡I\n\n"NOR,me);
    me->receive_heal("hp",1000);
    me->start_busy(1);
  }
  switch( random(30) )
  {
    case  0: message_vision("$N�@�����j���D�����n�ۧA�@�D�D�D\n",me);
          break;
    case  1: message_vision("$N�R�X�@�D�p�p�T���𮧡C\n",me);
          break;
    case  2: message_vision("$N�@�����j�����������|�P�A�M���y���C\n",me);
          break;
  }
  return;
}

int special_attack(object me, object target, int hitchance)
{
  object ob;
  if(!me) return 0;
  if(me->is_busy()) return 0;
  ob=find_living("_NPC_GRAVITY_BALL_");
  if( objectp(ob) )
  {
    if(!environment(ob) )
    {
      destruct(ob);
    }
  }
  else
  {
    me->start_busy(2);
    message_vision("\n$N"HIW"���o�K�¥��~�A�Ť��v���Φ��@��"HBK"�²y"HIW"�I\n"NOR,me);
    new(__DIR__"gravity-ball")->move(environment(me));
    return 1;
  }
  if(!random(8))
  {
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
    COMBAT_D->report_statue(target);
    return 1;
  }
  return 0;
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
  new(__DIR__"obj/obj/black-head")->move(this_object());
  new(__DIR__"eq/orochi-shield")->move(this_object());
  ob->add("popularity",10);      
  tell_object(ob,HIG"�A�o�� 10 �I�n��C"NOR);

  message("world:world1:vision",
  HIC"\n\t�i�F��q�j�G"+HIR" �X���s���ǨӾ_�ձ�Ť���G�z�A"HIY+ob->name(1)
  	 +HIR"�٤U�F"+name()+HIR"�����ŤF�C\n\n"NOR,users());

	if(random(1000)==978)
          new(__DIR__"eq/orochi-shield-save")->move(this_object());
  ::die();
  return;
}
