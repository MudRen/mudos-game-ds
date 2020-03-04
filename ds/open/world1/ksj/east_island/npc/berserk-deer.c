#include <ansi.h>
#include <combat.h>
inherit NPC;

void create()
{
  set_name(HIR"�g�ɤs��"NOR,({"berserk deer","deer"}) );
  set("long",@LONG
�@���g�㪺�����A�������o����A�٦ײ��`�a��X�A�i��O����K�[
�j�D���O���v�T�ҭP�C
LONG);
  set("race", "���~");    
  set("unit","��");
  set("age",20);
  set("level",43);
  set("attitude", "killer");  
  set("orochi_beast_1",1);
  add("addition_damage",50);
  add("addition_armor",30);
  set("limbs", ({ "�Y��", "����","�e��","���"}) ); 
  set("verbs", ({ "bite","crash" }) );  
  set("chat_chance", 10);
  set("chat_msg", ({
     (: random_move :),
     }));   
  setup();
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if(userp(this_player()) )
     this_object()->kill_ob(this_player());
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(7))
  {
    me->start_busy(1);
    COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_BERSERK);
    COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_BERSERK);
    COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_BERSERK);
    return 1;
  }
  else if(!random(7))
  {
    me->start_busy(1);
    COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_HEAVY);
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
  message_vision(HIG"\n�C�񪺧���q$N"HIG"���C��«�X�A�b�b�Ť��E�X�C\n\n",this_object());
  switch( random(10) )
  {
    case  0..5:
             new(__DIR__"devil-ghost")->move(environment(this_object()));
             break;
    case  6..8:
             new(__DIR__"devil-ghost")->move(environment(this_object()));
             new(__DIR__"devil-ghost")->move(environment(this_object()));
             break;
    case  9:
             new(__DIR__"devil-ghost")->move(environment(this_object()));
             new(__DIR__"devil-ghost")->move(environment(this_object()));
             new(__DIR__"devil-ghost")->move(environment(this_object()));
             break;
  }
  ::die();
  return;
}
