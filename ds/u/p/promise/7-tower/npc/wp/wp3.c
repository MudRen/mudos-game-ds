#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
  set_name(NOR+MAG"���]��"NOR , ({ "evil staff","staff" }) );
  set_weight(9000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�P�p�Ӿ��]������񪺧������L�A�����֦��۱j�P������A�b�Z�L�Q�ʬ���a�g�P�C\n"NOR);
    set("material", "sliver");
    set("value",12000);
    set("weapon_prop/con",2);
    set("weapon_prop/int",-2);
    set("limit_lv",40);
    set("limit_dex",30);
    set("limit_con",50);
    set("limit_int",50);
    set("limit_str",30);  
  }
    init_staff(55);
  setup();
} 

