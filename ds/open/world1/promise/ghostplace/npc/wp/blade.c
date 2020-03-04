#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
  set_name(HIR"蝦刃"NOR , ({ "shrimp blade","blade" }) ); 
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", "蝦的獒打造而成的。\n");
    set("material", "sliver");
    set("value",1000);
  }
  set("weapon_prop/str",1);
  set("weapon_prop/block",5);
  init_blade(40); 
  setup();
}

