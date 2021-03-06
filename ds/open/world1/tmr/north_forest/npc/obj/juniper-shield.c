#include <ansi.h>
#include <armor.h>
inherit SHIELD;

void create()
{
  set_name( "檜木盾",({"juniper shield","shield"}));
  set("long", @LONG
檜木為松柏類柏科，常綠喬木的一種，生長於海拔約一千五百公尺
至兩千五百公此之間。檜木含有大量精油即所謂的芬多精，優香無
辛味，木質性堅硬，耐朽力高不易腐蝕及不怕蛀蟲侵蝕之特性，拿
來做成盾牌，甚至比鐵盾還要來的堅固耐用。
LONG);
  set_weight(2400);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "面");
    set("volume",3);
    set("value", 3000);
    set("material","wood");
  }
  set("armor_prop/armor", 20);
  set("armor_prop/shield", 10);
  set("armor_prop/con", 2);
  set("armor_prop/dex", -1);
  setup();
}
