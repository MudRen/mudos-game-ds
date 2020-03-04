#include <weapon.h>
inherit FORK;
void create()
{
  set_name( "黃沙槍" , ({ "sand pike","pike" }) );
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", "這是由黃沙鐵製成的黃沙槍，是當地盜匪愛用之武器。\n");
    set("material", "iron");
    set("value",1500);
    set("volume",1);
  }
  init_fork(29);
  setup();
}