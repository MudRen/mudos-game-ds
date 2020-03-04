#include <ansi2.h>
#include <armor.h>
inherit CLOTH;

void create()
{
  set_name(HBK"黑鷹皮衣"NOR,({"eagle clothes","clothes"}) );
  set("long",@LONG
這是一件厚重的皮衣，上面刺了一隻巨大的黑鷹標誌，栩栩如生。
LONG
);
  set_weight(5100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "skin");
    set("unit", "件");
  }
  set("auto_set",2);
  set("armor_prop/armor",18);
  set("armor_prop/shield",7);
  set("armor_prop/dex",1);
  set("armor_prop/int",-1);
  setup();
}
