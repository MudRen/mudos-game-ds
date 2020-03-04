#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
  set_name(HIY"黃金面具"NOR,({"gold mask","mask"}));
  set("long", @LONG
純金製成的面具，相當值錢。
LONG
);
  set_weight(25000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "副");
    set("volume",1);
    set("value",24000);
    set("material","gold");
  }
  set("armor_prop/armor",4);
  setup();
}
