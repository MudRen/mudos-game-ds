#include <weapon.h>
inherit STAFF;

void create()
{
  set_name("�j���",({"huge stick","stick"}) );
  set("long","�@�⥨�j����ΡA�Ѿ�K��F�s���I\n");
  set_weight(50000);
  if (clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit","�K");
    set("volume",5);
    set("value",0);
    set("limit_str",105);
  }
  init_staff(50,TWO_HANDED);
  set("weapon_prop/hit",15);
  set("material","wood");
  setup();        
}
