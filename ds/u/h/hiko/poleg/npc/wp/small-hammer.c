#include <weapon.h>
inherit HAMMER;
void create()
{
  set_name("�u��",({"hammer"}));
  set("long","�@��p�p���u�l�C\n");
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
   else
   {
     set("unit", "��");
     set("material","iron");
   }
   set("value",800);
   init_hammer(10);
   setup();
}


