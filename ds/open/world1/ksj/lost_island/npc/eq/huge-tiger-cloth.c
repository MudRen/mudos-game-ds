#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
  set_name(HIY"虎紋皮衣"NOR ,({ "huge tiger cloth","cloth" }) );
  set("long",@LONG
這是以上古魔獸－劍牙巨虎之皮所製成的皮衣，不論是毛色還是
柔軟度，可說是皮衣中的極品!
LONG
);
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "件");
    set("value",20000);
    set("material", "fur");
  }
// 2003.3.30 新增 lv限制 by ksj
    set("limit_lv",40);
    set("armor_prop/shield",10);
    set("armor_prop/str",2);
    set("armor_prop/con",2);
    set("armor_prop/dex",1);
    set("armor_prop/armor", 20);

  setup();
}

