#include <weapon.h>
inherit BLADE;
void create()
{
  set_name( "黃沙刀" , ({ "sand blade","blade" }) );
  set_weight(1800);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", "這是由黃沙鐵製成的黃沙刀，是當地盜匪愛用之武器。\n");
    set("material", "iron");
    set("value",1200);
    set("volume",1);
  }
  init_blade(25);
  setup();
}