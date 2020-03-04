#include <ansi.h>
#include <armor.h>
inherit SURCOAT;
void create()
{
  set_name(YEL"狐皮"NOR"披風",({"fox surcoat","surcoat"}));
  set("long", @LONG   
一件用部份狐狸皮所製成的披風，摸起來十分的柔軟•防禦力會
因製作人的不同而有所改變•
LONG);
  set_weight(1200);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "件");
    set("volume",3);
    set("value",3000);
    set("material","fur");
  }
  set("limit_lv",15);
  set("armor_prop/armor",16+random(4));
  set("armor_prop/shield",10); 
  set("armor_prop/dex",2);
  set("armor_prop/con",2);
  setup();
}

