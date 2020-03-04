#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
  set_name(GRN"百鬼項鏈"NOR,({"hundred-bogle necklace","necklace"}) );
  set("long",@LONG
一百顆妖魂珠串成的項鏈，具有強大無比的法力。
LONG);
  set_weight(1200); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "串");
    set("value",20000);          
    set("volume", 3);                       
    set("material", "stone");
    set("limit_lv",35);
  }
  set("armor_prop/armor",10);       
  set("armor_prop/str",2);
  set("armor_prop/con",2);
  set("armor_prop/int",2);
  set("armor_prop/dex",2);
  setup();
}
