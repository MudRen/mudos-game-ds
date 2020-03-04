#include <ansi.h>
#include <armor.h>
inherit SHIELD;

void create()
{
  set_name(YEL"巨鼇甲盾"NOR,({"huge-turtle shield","shield"}));
  set("long", @LONG
巨鼇的殼甲製成的盾牌，非常的巨大沉重，幾乎可以擋住一個人的身體。
LONG
);
  set_weight(20000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "面");
    set("volume",5);
    set("value",8000);
    set("material","fur");
  }
// 2003.3.30 新增 lv限制 by ksj
  set("limit_lv",30);
  set("armor_prop/armor",29);
  set("armor_prop/dodge",-10);
  set("armor_prop/str",-1);
  set("armor_prop/dex",-3);
  setup();
}
