#include <armor.h>
inherit BOOTS;

void create()
{
  set_name("�Ѫ���j", ({ "tengu clog","clog" }) );
  set_weight(1200);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","�@���򳡯S������j�A��_�ӨϤH���H�@���C\n");
    set("unit", "��");
    set("material","wood");
    set("value",500);
  }
  set("armor_prop/con",1);
  set("armor_prop/armor", 3);
  setup();
}
