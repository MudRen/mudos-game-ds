#include <weapon.h>
inherit FORK;

void create()
{
  set_name("��e", ({"fork" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�e�ݤ�����K���K�e�A�O�@��s��`�Ϊ��Z���C\n");
    set("value",800);
    set("volume",4);
    set("material","steel");
  }
  init_fork(20,TWO_HANDED);
  setup();
}
