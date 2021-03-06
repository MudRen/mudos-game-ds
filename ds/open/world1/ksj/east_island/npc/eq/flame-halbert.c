#include <ansi.h>
#include <combat.h>
#include <weapon.h>
inherit FORK;

void create()
{
  set_name(HIR"燄舞"NOR, ({ "flame halbert","halbert" }) );
  set("long",@long
槍尖燃燒淡淡火燄，槍頭上嵌著一顆赤紅的小珠子，揮動時火蛇亂竄
充滿氣勢。
long);      
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("value",3000);
    set("volume",3);
    set("material","steel");
  }
  set("limit_str",30);
  set("limit_skill",50);
  set("limit_lv",20);
  set("weapon_prop/hit",5);
  init_fork(45,TWO_HANDED);
  setup();
}

void attack(object me, object victim)
{
  int damage;
  ::attack();
  if(!me) return;
  if(!victim) return;
  if( me->query("mp") < 25 ) return;
  damage=200+random(50)+(me->query_int())-(victim->query_shield());
  if (damage<0) damage=0;

  if( (me->query("id") == "red tengu") && (!random(7)) )
  {
    message_vision(HIR"燄舞槍尖發出一陣紅光！\n"NOR,me,victim);
    COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),TYPE_HEAVY);
    me->start_busy(1);
  }
  else if( me->query_dex()>30 && !random(10) )
  {
    message_vision("$N"HIR"揮動燄舞形成一圈火輪卷向$n！造成$n("+damage+")的燒傷\n"NOR,me,victim);
    victim->receive_damage("hp", damage,me);
    me->receive_damage("mp",20);
    me->add_busy(1);  
  }
  return;
}
