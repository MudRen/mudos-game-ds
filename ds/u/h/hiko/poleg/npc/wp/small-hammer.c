#include <weapon.h>
inherit HAMMER;
void create()
{
  set_name("短鎚",({"hammer"}));
  set("long","一把小小的短槌。\n");
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
   else
   {
     set("unit", "把");
     set("material","iron");
   }
   set("value",800);
   init_hammer(10);
   setup();
}


