#include <weapon.h>
inherit SWORD;
void create()
{
  set_name( "黃沙劍" , ({ "sand sword","sword" }) );
  set_weight(1500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", "這是由黃沙鐵製成的黃沙劍，是當地盜匪愛用之武器。\n");
    set("material", "iron");
    set("value",1100);
    set("volume",1);
  }
  init_sword(23);
  setup();
}