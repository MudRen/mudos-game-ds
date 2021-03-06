#include <ansi.h>
#include <combat.h>
inherit NPC;

void create()
{
  set_name(HIR"狂暴小熊"NOR,({"berserk small bear","small bear","bear"}) );
  set("long",@LONG
一隻小黑熊，全身散發妖氣，肌肉異常地突出，可能是受到八歧大蛇
邪力的影響所致。
LONG);
  set("race", "野獸");    
  set("unit","隻");
  set("age",40);
  set("level",42);
  set("attitude", "killer");  
  set("orochi_beast_1",1);
  add("addition_damage",50);
  add("addition_armor",50);
  set("limbs", ({ "頭部", "身體","前肢","後肢"}) ); 
  set("verbs", ({ "bite","claw" }) );    
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
  message_vision(HIG"\n青綠的妖氣從$N"HIG"的七孔竄出，在半空中聚合。\n\n",this_object());
  switch( random(10) )
  {
    case  0..6:
             new(__DIR__"devil-ghost")->move(environment(this_object()));
             break;
    case  7..8:
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
