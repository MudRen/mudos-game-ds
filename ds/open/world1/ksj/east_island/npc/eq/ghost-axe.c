#include <ansi.h>
#include <weapon.h>
inherit AXE;

void create()
{
  set_name("雙刃鬼斧", ({"ghost axe","axe" }) );
  set_weight(20000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", "一把巨大的雙刃鐵斧，可以輕易地將人劈成兩半。\n");
    set("value",5000);
    set("volume",7);
    set("material","steel");
    set("limit_str",70);
    set("limit_lv",35);
  }
  set("weapon_prop/dex",-3);
  set("weapon_prop/hit",5);
  init_axe(60,TWO_HANDED);
  setup();
}

void attack(object me,object victim)
{
  ::attack();
  if(!me) return;
  if(!victim) return;
  if(me->is_busy()) return;
  if(random(6)) return;
  message_vision(HIR"$N手中的雙刃鬼斧突然變得通紅！\n"NOR,me);
  COMBAT_D->do_attack(me, victim, this_object(), 4);
  COMBAT_D->report_statue(victim);
  victim->add_busy(1);
  return;
}
