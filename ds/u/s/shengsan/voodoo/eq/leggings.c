
#include <armor.h>

inherit LEGGINGS;

void create()
{
  set_name("�C���@�L",({"leggings"}));
	set_weight(2760);
set("long","�o�O�ΫC�˵����ְ������@�L�C\n");
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("material", "leather");
    set("unit","��");
set("value",3000);
	set("armor_prop/armor",55);
	set("limit_lv",55);
  }

  setup();

}
