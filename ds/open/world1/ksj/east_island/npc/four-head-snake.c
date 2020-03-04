#include <ansi.h>
#include <combat.h>
inherit NPC;

void create()
{
  set_name(HIG"�|�Y���D"NOR,({"four head snake","snake"}) );
  set("long",@LONG
�@���j�����`�����D�A��i�Ȫ��O�������|���Y�A����K���j�D���O
���l�ޡA���Ͻ��s���h�~�ӳy�����鲧�ܡC
LONG);
  set("race", "���~");    
  set("unit","��");
  set("age",170);
  set("level",50);
  set("attitude", "killer");  
  set("orochi_beast_2",1);
  add("addition_damage",50);
  add("addition_armor",70);
  set("limbs", ({ "�Y��", "����","����"}) ); 
  set("verbs", ({ "bite" }) );
  set("chat_chance", 10);
  set("chat_msg", ({
     (: random_move :),
     }));        
  setup();
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if( !random(7) )
  {
    me->start_busy(1);
    message_vision("\n$N"HIR"�|���Y�e�t�V$n�@�}�r��I\n\n"NOR, me, target);
    COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_BERSERK);
    COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_BERSERK);
    COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_BERSERK);
    COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_BERSERK);
    return 1;
  }
  else if(!random(7))
  {
    COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_HEAVY);
    COMBAT_D->report_statue(target);
    me->start_busy(1);
    return 1;
  }
  else if( random(target->query_dex()) < 4)
  {
    message_vision(HIR"\n$N�����ڨ��t���$n������A�N$n�����I\n\n"NOR, me, target);
    target->add_busy(3);
    me->start_busy(1);
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
  ob->add("popularity",1);      
  tell_object(ob,HIG"�A�o�� 1 �I�n��C"NOR);
  switch( random(10) )
  {
    case  0..4: new(__DIR__"eq/four-snake-surcoat")->move(this_object());
          break;
  }
  ::die();
  return;
}
