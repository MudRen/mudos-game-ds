#include <armor.h>
#include <ansi.h>
inherit PANTS;
void create()
{
  set_name(HIR"���T���"NOR ,({ "fire-wolf pants","pants" }) );
  set("long","���T��ֻs������ǡA���������ܥO�H�߷R�A��_�ӵΪA�ӻ��K�C");
  set_weight(1300);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",2);
    set("unit", "��");
    set("value",3000);
  }
  set("armor_prop/armor",6);
  set("armor_prop/shield",3);
  set("armor_prop/dex", 2);
  setup();
}
