#include <weapon.h>
inherit STAFF;

void create()
{
  set_name("�˨���",({"thorn stick","stick"}) );
  set("long","�@�⥨�j����ΡA�Ѱ�w����F�s���A�W�����G�˨�A�W�[���ֱ��ˤO�C\n");
  set_weight(30000);
  if (clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit","�K");
    set("volume", 3);
    set("value", 1200);
  }
  init_staff(45, TWO_HANDED);
  set("material","wood");
  set("weapon_prop/dex",-1);
  set("weapon_prop/str",1);
  setup();        
}
