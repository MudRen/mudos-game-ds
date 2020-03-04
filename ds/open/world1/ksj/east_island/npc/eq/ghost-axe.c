#include <ansi.h>
#include <weapon.h>
inherit AXE;

void create()
{
  set_name("���b����", ({"ghost axe","axe" }) );
  set_weight(20000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�@�⥨�j�����b�K��A�i�H�����a�N�H�A����b�C\n");
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
  message_vision(HIR"$N�⤤�����b�����M�ܱo�q���I\n"NOR,me);
  COMBAT_D->do_attack(me, victim, this_object(), 4);
  COMBAT_D->report_statue(victim);
  victim->add_busy(1);
  return;
}
