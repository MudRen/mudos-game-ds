#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
  set_name(HIG"人魚項鏈"NOR,({"ningyo necklace","necklace"}) );
  set("long",@LONG
綠色珠子串成的項鏈，是人魚搜集水中的綠玉所製成。
LONG);
  set_weight(700); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "串");
    set("value",5000);          
    set("volume", 2);                       
    set("material", "stone");
  }
  set("armor_prop/armor",2);       
  set("armor_prop/con",3);
  setup();
}
