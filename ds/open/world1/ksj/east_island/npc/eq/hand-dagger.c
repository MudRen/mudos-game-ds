#include <ansi.h>
#include <weapon.h>
inherit DAGGER;

void create()
{
  set_name("鐵手刀", ({ "hand dagger","dagger" }) );
  set_weight(1500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "柄");
    set("long", "鐵製的短刀片，刀刃尾端的鐵條朝刀背彎成橢圓形，手握著可以用於\n"
                "近身格鬥。\n");
    set("value",700);
    set("volume",2);
    set("material","steel");
  }
  init_dagger(15);
  setup();
}
