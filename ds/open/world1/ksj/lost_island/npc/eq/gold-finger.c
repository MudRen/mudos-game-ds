#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
  set_name(HIY"黃金戒指"NOR,({"gold finger","finger"}));
  set("long", @LONG
純金製成的戒指，值不少錢。
LONG
);
  set_weight(600);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "只");
    set("volume",1);
    set("value",2880);
    set("material","gold");
  }
  set("armor_prop/armor",1);
  setup();
}
