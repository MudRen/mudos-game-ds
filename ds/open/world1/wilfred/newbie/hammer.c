#include <weapon.h>
inherit HAMMER;
void create()
{
  set_name("���K��",({"hammer"}));
  set("long","�K�K�̷R�Ϊ��K��C\n");
  set_weight(6800);
  if( clonep() )
    set_default_object(__FILE__);
   else
   {
     set("unit", "��");
     set("material","iron");
   }
   set("value",1000);
   init_hammer(20);
   setup();
}

