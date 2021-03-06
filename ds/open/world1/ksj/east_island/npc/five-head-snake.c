#include <ansi.h>
#include <combat.h>
inherit NPC;

void heal();

void create()
{
  set_name(HIG"五頭巨蛇"NOR,({"five head snake","snake"}) );
  set("long",@LONG
一隻大的異常的巨蛇，更可怕的是它竟有五個頭，受到八岐大蛇邪力
的吸引，蟠踞山中多年而造成身體異變。
LONG);
  set("race", "野獸");    
  set("unit","隻");
  set("age",190);
  set("level",55);
  set("attitude", "killer");  
  set("orochi_beast_2",1);
  add("addition_damage",70);
  add("addition_armor",90);
  set("limbs", ({ "頭部", "身體","尾巴"}) ); 
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
    message_vision("$N吸取地上的邪氣治療傷勢。\n",this_object());
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
    message_vision("\n$N"HIR"五個頭疾速向$n一陣猛攻！\n\n"NOR, me, target);
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
    message_vision(HIR"\n$N的尾巴迅速纏住$n的身體，將$n緊緊絞纏！\n\n"NOR, me, target);
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
  tell_object(ob,HIG"你得到 2 點聲望。"NOR);
  switch( random(10) )
  {
    case  0..9: new(__DIR__"eq/five-snake-surcoat")->move(this_object());
          break;
  }
  ::die();
  return;
}
