#include <weapon.h>
inherit FORK;

void create()
{
  set_name("���I", ({"halbert" }) );
  set_weight(3500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "���ۤj�p�Ⱖ�j�b�����j�C\n");
    set("value",1200);
    set("volume",4);
    set("material","steel");
  }
  init_fork(30,TWO_HANDED);
  setup();
}
