#include <weapon.h>
inherit STAFF;

void create()
{
  set_name("���",({"wood stick","stick"}) );
  set("long","�@�K�βʾ�K�s������ΡC\n");
  set_weight(2000);
  if (clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit","�K");
    set("volume",2);
    set("value",0);
  }
  init_staff(15);
  set("material","wood");
  setup();        
}
