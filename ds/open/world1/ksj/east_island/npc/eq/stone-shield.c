#include <armor.h>
inherit SHIELD;

void create()
{
  set_name("�ۤ���",({"stone shield","shield"}));
  set("long", @LONG
�@���ѵM���۪O�A���ӷ�@�޵P�ˬO�Z�X�Ϊ��C
LONG);
  set_weight(5000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",4);
    set("value",100);
    set("material","stone");
  }
  set("armor_prop/armor",10);
  setup();
}
