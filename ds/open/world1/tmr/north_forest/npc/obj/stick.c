#include <weapon.h>
inherit STAFF;

void create()
{
  set_name("���",({"wood stick","stick"}) );
  set("long","�@�⥨�j����ΡA�Ѱ�w����F�s���C\n");
  set_weight(20000);
  if (clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit","�K");
    set("volume", 2);
    set("value", 500);
  }
  init_staff(35, TWO_HANDED);
  set("material","wood");
  setup();        
}
