
#include <armor.h>

inherit CLOAK;

void create()
{
  set_name("����ܭ�",({"cloak"}));
  set("long","�o�O�@���A���⪺�ܭ�\n");
	set_weight(3500);
  if( clonep() )
      set_default_object(__FILE__);
  else {
      set("material","hands");
      set("unit","��");
set("value",3800);
      set("armor_prop/armor",70);
      set("limit_lv",70);
  }

  setup();

}
