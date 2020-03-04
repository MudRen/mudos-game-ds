#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
  set_name(HIY"黃金腰帶"NOR,({"gold waist","waist"}));
  set("long", @LONG
純金製成的腰帶，相當值錢。
LONG
);
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "副");
    set("volume",2);
    set("value",14400);
    set("material","gold");
  }
  set("armor_prop/armor",3);
  setup();
}
