#include <weapon.h>
inherit FIST;
void create()
{
  set_name( "�ۤ�" , ({ "stone claw","claw" }) );
  set_weight(5000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "���Y�s�����ۤ��A�S�j�S���C\n");
    set("material", "stone");
    set("value",2700);
    set("volume",1);
    set("limit_con",15);
    set("limit_str",15);
    set("weapon_prop/str",1);
    set("weapon_prop/dex",-1);
  }
  init_fist(36);
  setup();
}
