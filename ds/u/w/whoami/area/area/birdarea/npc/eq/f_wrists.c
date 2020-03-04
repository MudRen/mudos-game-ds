#include <ansi.h>
#include <armor.h>
inherit WRISTS; 
void create()
{
  set_name(YEL"狐骨"NOR"腕輪",({"fox wrists","wrists"}));
  set("long", @LONG
一件用狐狸的骨頭裝成的護腕，在護腕上還裝上了刺，加強了攻
擊力•防禦力、攻擊力皆會因製作人的不同而有所改變•
LONG);
  set_weight(1200);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "件");
    set("volume",3);
    set("value",6000);
    set("material","fur");
  }
  set("limit_lv",25);
  set("armor_prop/damage",7+random(4));
  set("armor_prop/armor",8+random(4));
  set("armor_prop/shield",6); 
  set("armor_prop/dex",-2); 
  set("armor_prop/str",1);
  set("armor_prop/con",2);
  setup();
}

