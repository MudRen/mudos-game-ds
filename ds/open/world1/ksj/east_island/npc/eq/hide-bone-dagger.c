#include <ansi.h>
#include <weapon.h>
inherit DAGGER;

void create()
{
  set_name(CYN"����"HIR"��"HIW"�u�b"NOR, ({ "hide-bone dagger","dagger" }) );
  set_weight(2100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "�`");
    set("long", "�H�H�����M�T���u�M�A�M�b�x�۫C�Ū�����C\n");
    set("value",3700);
    set("volume",3);
    set("material","blacksteel");
  }
  set("weapon_prop/dex",2);
  set("weapon_prop/hit",5);
  set("backstab_bonus",50);
  init_dagger(40);
  setup();
}
