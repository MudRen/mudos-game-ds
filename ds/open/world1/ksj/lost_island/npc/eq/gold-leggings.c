#include <ansi.h>
#include <armor.h>
inherit LEGGING;

void create()
{
  set_name(HIY"黃金脛甲"NOR,({"gold leggings","leggings"}));
  set("long", @LONG
純金製成的脛甲，只是值錢而已，並無實際的防護力。
LONG
);
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "副");
    set("volume",3);
    set("value",19200);
    set("material","gold");
  }
  set("armor_prop/armor",9);
  setup();
}
