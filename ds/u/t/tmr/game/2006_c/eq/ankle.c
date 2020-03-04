#include <ansi.h>
#include <armor.h>
inherit ANKLE;
void create()
{
  set_name(HIR"聖誕"HIW"快樂足鍊"NOR,({"christmas ankle","ankle"}));
  set("long", @LONG  
這是一串聖誕老人愛用的足鍊，簡簡單單的線條，搭配著寶石的設計，
塑造出聖誕節的歡樂氣氛，搭配任何服裝都非常好看。
LONG);
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "串");
    set("volume", 3);
    set("value", 50000);
    set("material","gold");
  }
  set("armor_prop/int",1 + random(3) );
  set("armor_prop/str",1 + random(3) );
  set("armor_prop/dex",1 + random(3) );
  set("armor_prop/con",1 + random(3) );
  set("armor_prop/armor", 5 + random(20) );
  setup();
}

