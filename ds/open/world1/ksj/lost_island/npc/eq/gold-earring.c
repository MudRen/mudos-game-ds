#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
  set_name(HIY"黃金耳環"NOR,({"gold earring","earring"}));
  set("long", @LONG
純金製成的耳環，閃耀令人沉醉的金光。
LONG
);
  set_weight(400);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "對");
    set("volume",1);
    set("value",1920);
    set("material","gold");
  }
  set("armor_prop/armor",1);
  setup();
}
