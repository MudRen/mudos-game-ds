#include <armor.h>
inherit SHIELD;
void create()
{
  set_name("���" ,({ "wooden shield","shield" }) );
  set("long","���q����s��ޡA�軴�@�ΡC");
  set_weight(2000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "wood");
    set("volume",1);
    set("unit", "��");
    set("value",800);
  }
  set("armor_prop/armor",10);
  setup();
}