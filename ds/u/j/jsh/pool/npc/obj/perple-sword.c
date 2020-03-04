#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit SWORD;
void create()
{
  set_name(HIY"紫煌定風劍"NOR , ({ "perple-light sword","sword" }) );
  set_weight(2500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", "紫煌定風劍，乃古英雄竭達羅與巨鵰激戰後之遺物，為何是遺物，可想而知。\n");
    set("material", "gold");
    set("value",10000);
    set("weapon_prop/str",3);
    set("weapon_prop/con",2);
    set("weapon_prop/dex",1);
    set("weapon_prop/bar",1);
    set("weapon_prop/dodge",10);
    set("weapon_prop/sword",10);    
    set("replica_ob",__DIR__"perple-sword2");
}
    set("wield_msg",HIW"$N抽出$n，瞬間捲起一陣陣強風！\n"NOR);
    init_sword(63+random(3)); 
  setup();
}
void attack(object me, object victim)
{
    int damage,tk_one;

    ::attack();
    if(!me) return;
    if(!victim) return;

    if(me->query_skill("sword") > 70 && me->query_str() > 30 && random(10)<3 )
    {
      message_vision(HIW "\n『轟』的一聲！$N手中的"HIY"紫煌定風劍"HIW"爆出四彩紫光，直直奪向$n的雙眼！！\n" NOR,me,victim);
      damage += me->query_skill("sword")+me->query_str()+random(40);
      tk_one += victim->query_skill("parry")+victim->query_dex();
      tk_one = tk_one/3;
      if(damage-tk_one>0 && random(10)>5)
      {
        damage=damage+random((damage-tk_one));
        message_vision(HIR "$N狂嚇一聲！跟著••雙眼便流下的鮮血••\n"NOR,victim);
        victim->receive_damage("hp",damage, me);
      }
      else message_vision(HIG "$N轉身閉眼, 閃開了刺目的的紫光。\n"NOR,victim);
    }
    return;
}

