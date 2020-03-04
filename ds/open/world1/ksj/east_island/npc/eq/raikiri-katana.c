#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
  set_name(HIC"雷切"NOR,({"raikiri katana","katana"}));
  set("long",@LONG
一把漂亮的長刀，傳說能斬斷雷電具有呼風喚雨的能力。
LONG);
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_skill",60);
    set("unit", "把");
    set("weapon_prop/str",2);        
    set("value",5500);
    set("volume",3);        
    set("material","blacksteel");       
  }        
  init_blade(51,TWO_HANDED);
  setup();
}
