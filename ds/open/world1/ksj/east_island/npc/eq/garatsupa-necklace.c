#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
  set_name(HIG"河童玉"NOR,({"garatsupa necklace","necklace"}) );
  set("long",@LONG
凝聚河童生命的青綠色寶玉，具有神奇的力量。
LONG);
  set_weight(700); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "串");
    set("value",20000);          
    set("volume", 2);                       
    set("material", "stone");
    set("limit_lv",30);
  }
  set("armor_prop/armor",1);       
  set("armor_prop/dex",2);
  set("armor_prop/int",3);
  set("armor_prop/con",1);
  set("armor_prop/str",1);
  setup();
}
