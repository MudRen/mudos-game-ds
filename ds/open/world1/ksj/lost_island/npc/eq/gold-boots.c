#include <ansi.h>
#include <armor.h>
inherit BOOTS;

void create()
{
  set_name(HIY"黃金長靴"NOR,({"gold boots","boots"}));
  set("long", @LONG
純金製成的靴子，相當值錢。
LONG
);
  set_weight(8000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "雙");
    set("volume",5);
    set("value",38400);
    set("material","gold");
  }
  set("armor_prop/armor",9);
  setup();
}
