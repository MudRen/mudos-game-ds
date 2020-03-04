#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
  set_name(MAG"獅爪靴"NOR, ({ "chimera boots","boots" }) );
  set_weight(1200);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","魔獸  奇美拉的前腳製成的靴子，靴子前的利爪增加了不少傷害力。\n");
    set("unit", "雙");
    set("material","fur");
    set("value",8000);
// 2003.3.30 新增 lv限制 by ksj
    set("limit_lv",35);
    set("armor_prop/dex",1);
    set("armor_prop/con",1);
    set("armor_prop/damage",5);
    set("armor_prop/shield",3);
    set("armor_prop/armor", 8);
  }
  setup();
}
