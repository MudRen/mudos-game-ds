#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
  set_name(HIY"黃金項鏈"NOR,({"gold necklace","necklace"}));
  set("long", @LONG
純金製成的項鏈，值不少錢。
LONG
);
  set_weight(800);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "條");
    set("volume",1);
    set("value",3840);
    set("material","gold");
  }
  set("armor_prop/armor",2);
  setup();
}
