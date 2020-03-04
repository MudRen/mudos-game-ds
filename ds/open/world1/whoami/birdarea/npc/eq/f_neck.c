#include <ansi.h>
#include <armor.h>
inherit NECK;
void create()
{
  set_name(YEL"狐牙"NOR"鏈",({"fox necklace","necklace"}));
  set("long", @LONG  
一件用狐狸牙齒所串接而成的項鍊，有些牙齒還沒裝整齊，你被
牙齒刺到戴起來不太舒服防禦力會因製作人的不同而有所改變•
LONG);
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "串");
    set("volume",3);
    set("value",3000);
    set("material","fur");
  }
  set("limit_lv",10);
  set("armor_prop/armor",8+random(4));
  set("armor_prop/shield",8); 
  set("armor_prop/dex",-2);
  set("armor_prop/con",2); 
  set("armor_prop/str",2);
  setup();
}

