#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
  set_name(HIR"赤繫威大鎧"NOR ,({ "red armor","armor" }) );
  set("long",@LONG
一件裝飾華麗，霸氣十足的戰鎧，用鐵片及籐條製成，兼顧防禦力與
輕便性，綴以名貴的裝飾，並不是一般人有資格穿著的。
LONG);
  set_weight(6000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",5);
    set("unit", "副");
    set("value",12000);
  }
  set("limit_con",40);
  set("limit_lv",30);
  set("armor_prop/armor",28);
  set("armor_prop/bar",1);
  set("armor_prop/tec",-1);
  set("armor_prop/dex",-1);
  setup();
}
