#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
  set_name(HIB"�����s�M"NOR, ({ "sailorman blade","blade" }) );
  set_weight(2300);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�@�⦳���׵u�M�A�@�볣����ҨϥΡC\n");
    set("material", "steel");
    set("value",1400);
    set("limit_str",10);
  }
  init_blade(15+random(4));
  setup();
}
