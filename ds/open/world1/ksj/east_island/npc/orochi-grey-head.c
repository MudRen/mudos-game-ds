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
  set_name(GRN"�K���j�D"RED"�D"NOR"�ǭ�"NOR,({"orochi grey head","grey head","head","_GREY_HEAD_"}) );
  set("long",@LONG
�K�Y�K���A���j���ߦ��p�K�y�s�p�P�K�Ӥs���@�몺���Ƥj�D���W��
���B�̡A������K�y�s���B�s���A�����w�ۨ���C�A�{�b�Ҭݨ쪺��
���O�K���j�D���K���Y���@�A�ɭ��g�����Ǧ�D���C
LONG
);
    set("attack_merits","bar");
    set("race","beast");
  set("unit","��");
  set("age",2000);
  set("attitude", "aggressive");
  set("evil",200);
  set("level",70);
  set("orochi",1);
  set("orochi_beast_3",1);
  set("limbs", ({ "�B��","�|��","����","�Y��"}) ); 
  set("verbs", ({ "bite","crash"}) );     
  set("Merits/bar",13);
  set("Merits/bio",11);
  set("Merits/wit",4);
  set("Merits/tec",7);
  set("Merits/sou",4);
  add("addition_damage",50);
  add("addition_armor",220);
  add("addition_shield",80);
  set_temp("apply/hit",40);
  set("chat_chance", 30);
  set("chat_msg",({
     (: normal_ai() :),
     (: random_move :),
  }) );
  setup();
  set("default_actions", (: call_other, __FILE__, "query_action" :));
  set("actions", (: call_other, __FILE__, "query_action" :));
  set_living_name("_NPC_GREY_HEAD_");
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
  int damage,hp;
  if(!me) return 0;
  if(me->is_busy()) return 0;
  hp=target->query("hp");
  if( !random(4) && (target->query_dex()<120) ) 
  {
    me->start_busy(2);
    target->add_busy(1);
    message_vision("\n$N"HIW"�r�M�r��$n������A�ƨg�a���r�åϡI\n"NOR,me,target);
    damage=hp/7;
    if( target->query_dex() < 120) call_out("bite",1,damage,target);
    damage=hp/8;
    if( target->query_dex() < 100) call_out("bite",1,damage,target);
    damage=hp/9;
    if( target->query_dex() < 80) call_out("bite",1,damage,target);
    damage=hp/10;
    if( target->query_dex() < 60) call_out("bite",1,damage,target);
    damage=hp/11;
    if( target->query_dex() < 50) call_out("bite",1,damage,target);
    damage=hp/12;
    if( target->query_dex() < 30) call_out("bite",1,damage,target);
    return 1;
  }
  else if(!random(8))
  {
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
    COMBAT_D->report_statue(target);
    return 1;
  }
  return 0;
}

void bite(int damage,object target)
{
  message_vision("\n$N"HIR"�����Q�Q���r�o�˲�����("+damage+")�I\n"NOR,target);
  target->receive_damage("hp", damage, this_object());
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
  ob->add("popularity",10);      
    new(__DIR__"obj/obj/grey-head")->move(this_object());
new(__DIR__"eq/orochi-armor")->move(this_object());
  tell_object(ob,HIG"�A�o�� 10 �I�n��C"NOR);

  message("world:world1:vision",
	HIC"\n\t�i�F��q�j�G"+HIR" �X���s���ǨӾ_�ձ�Ť���G�z�A"HIY+ob->name(1)
  	 +HIR"�٤U�F"+name()+HIR"�����ŤF�C\n\n"NOR,users());
  	
  	if(random(1000)==978)
          new(__DIR__"eq/orochi-armor-save")->move(this_object());
  ::die();
  return;
}
