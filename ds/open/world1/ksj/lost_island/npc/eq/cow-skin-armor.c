#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
  set_name("刺牛皮甲",({ "cow-skin armor","armor" }) );
  set("long",@LONG
這是刺牛皮製成的皮甲，充滿尖刺相當有威脅感，而且牛皮堅韌耐砍
，是件不錯的皮甲。
LONG
);
  set_weight(4000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",4);
    set("unit", "件");
    set("value",7500);
  }
  set("limit_con",25);
  set("armor_prop/armor",27);
  set("armor_prop/con",2);
  set("armor_prop/dex",-1);
  set("armor_prop/damage",4);
  setup();
}
