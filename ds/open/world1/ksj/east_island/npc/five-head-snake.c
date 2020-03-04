#include <ansi.h>
#include <combat.h>
inherit NPC;

void heal();

void create()
{
  set_name(HIG"���Y���D"NOR,({"five head snake","snake"}) );
  set("long",@LONG
�@���j�����`�����D�A��i�Ȫ��O�����������Y�A����K���j�D���O
���l�ޡA�Ͻ��s���h�~�ӳy�����鲧�ܡC
LONG);
  set("race", "���~");    
  set("unit","��");
  set("age",190);
  set("level",55);
  set("attitude", "killer");  
  set("orochi_beast_2",1);
  add("addition_damage",70);
  add("addition_armor",90);
  set("limbs", ({ "�Y��", "����","����"}) ); 
  set("verbs", ({ "bite" }) );
  set("chat_chance", 15);
  set("chat_msg", ({
     (: heal :),
     (: random_move :),
     }));        
  setup();
}

void heal()
{
  if( query("hp")+500 < query("max_hp") )
  {
    message_vision("$N�l���a�W������v���˶աC\n",this_object());
    add("hp",250+random(200));
    return;
  }
  return;
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(7))
  {
    me->start_busy(1);
    message_vision("\n$N"HIR"�����Y�e�t�V$n�@�}�r��I\n\n"NOR, me, target);
    COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_BERSERK);
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
  else if( random(target->query_dex()) < 5)
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
  ob->add("popularity",2);      
  tell_object(ob,HIG"�A�o�� 2 �I�n��C"NOR);
  switch( random(10) )
  {
    case  0..9: new(__DIR__"eq/five-snake-surcoat")->move(this_object());
          break;
  }
  ::die();
  return;
}
