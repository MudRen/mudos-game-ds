#include <armor.h>
inherit PANTS;

void create()
{
  set_name("�Ѫ���" ,({ "tengu pants","pants" }) );
  set("long","�@��e�P�����ǡA�W���V�ۤ��m���C��C");
  set_weight(800);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",1);
    set("unit", "��");
    set("value",500);
  }
  set("armor_prop/armor",2);
  set("armor_prop/shield",3);
  set("armor_prop/dex", 1);
  setup();
}
