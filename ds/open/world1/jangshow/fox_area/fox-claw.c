#include <ansi.h>
#include <weapon.h> 
inherit F_UNIQUE;
inherit FIST;
void create()
{
  set_name(HIW"白狸"HIR"燐"HIW"爪"NOR , ({ "fox-fire claw","claw" }) );
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", "九尾妖弧的前爪，透著火紅色的光芒，不時還會激出火花。\n");
    set("material", "gold");
    set("value",25000);
    set("weapon_prop/str",3);
    set("weapon_prop/dex",3);
    set("weapon_prop/int",3);  
 
    set("replica_ob",__DIR__"fox-claw2");
  } 
  set("weapon_prop/bar",2); 
  set("weapon_prop/tec",-2); 
  set("beast_weapon_prop/damage",60);
  init_fist(60+random(this_player()->query("level")/3));
  setup();
} 

void attack(object me, object victim)
{
    int damage,tk_one;

    ::attack();
    if(!me) return;
    if(!victim) return;

    if(me->query_skill("unarmed") > 80 && me->query_str() > 30 && random(10)<3 )
    {
      message_vision(HIR"一道火光閃開，"+HIW"九尾"+HIR+"無窮的能量瞬間灌向$n！！\n\n" +NOR,me,victim);
      damage += me->query_skill("unarmed")+me->query_str()+random(50);
      tk_one += victim->query_skill("dodge")+victim->query_dex();
      tk_one = tk_one/3;
      if(damage-tk_one>0 && random(10)>5)
      {
        damage=damage+random((damage-tk_one));
        message_vision(HIR "只見"+victim->query("name")+"渾身透紅，巨大的能量！驟然爆開！\n\n"NOR,victim);
        victim->receive_damage("hp",damage, me);
      }
    return; 
    }
}

