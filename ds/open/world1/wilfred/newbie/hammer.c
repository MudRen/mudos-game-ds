#include <weapon.h>
inherit HAMMER;
void create()
{
  set_name("打鐵鎚",({"hammer"}));
  set("long","鐵匠們愛用的鐵鎚。\n");
  set_weight(6800);
  if( clonep() )
    set_default_object(__FILE__);
   else
   {
     set("unit", "把");
     set("material","iron");
   }
   set("value",1000);
   init_hammer(20);
   setup();
}

