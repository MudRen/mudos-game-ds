#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
  set_name(HIB"觀雲刀"NOR, ({ "look sky blade","blade" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", "這是由鐵剛所製成的大刀，是一把殺人俐落的寶刀。\n");
    set("material", "steel");
    set("value",2200);
    set("volume",5);
  }
          set("limit_dex",25);
          set("weapon_prop/con",1);
          set("weapon_prop/dex",1);
  init_blade(35);
  setup();
}


