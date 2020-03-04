#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
  set_name(HIG"相柳鱗衣"NOR ,({ "xiangliu cloth","cloth" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long",@LONG
妖獸  相柳的鱗皮製成的皮衣，防禦力雖然普通但具有一些妖力
，整件鱗衣帶有一點腥味。
LONG
);
    set("unit", "件");
    set("value",8000);
    set("material", "fur");
    set("armor_prop/shield",15);
    set("armor_prop/str",-2);
    set("armor_prop/con",1);
    set("armor_prop/dex",2);
    set("armor_prop/armor", 10);
  }
  setup();
}
