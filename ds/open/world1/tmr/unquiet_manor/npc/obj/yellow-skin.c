#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
  set_name("黃皮子衣" ,({ "yellow-skin cloth","cloth" }) );
  set("long",@LONG
黃皮子即是所謂的「黃鼠狼」，是最奸詐狡滑的生物。這件就是
用黃皮子的皮所製成的一件皮衣。
LONG
);
  set_weight(300);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "件");
    set("value", 1000);
    set("material", "fur");
  }
    set("armor_prop/int", 1);
    set("armor_prop/shield",10);
    set("armor_prop/armor", 5);

  setup();
}

