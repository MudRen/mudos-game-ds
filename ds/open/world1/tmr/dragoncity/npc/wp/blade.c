#include <weapon.h>
inherit BLADE;
void create()
{
    set_name( "大刀" , ({ "broad blade","blade" }) );
  set_weight(1500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", "這是一把厚重的大刀。\n");
    set("material", "iron");
    set("value", 500);
    set("volume",1);
  }
  init_blade(20);
  setup();
}

