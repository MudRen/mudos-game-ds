#include <ansi.h>
#include <armor.h>
inherit NECK;
void create()
{
  set_name(HIG"牧神玉墜"NOR,({"pan necklace","necklace"}));
  set("long", @LONG  
這是一條牧神潘恩所穿的玉墜，造型美幻脫俗，光彩不斷的變幻。
LONG
);
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "串");
    set("volume", 3);
    set("value", 6000);
    set("material","gold");
  }
  set("limit_lv",25);
  set("armor_prop/armor", 8);
  set("armor_prop/shield", 8); 
  set("armor_prop/int", 2); 
  set("armor_prop/con", 1); 
  setup();
}


