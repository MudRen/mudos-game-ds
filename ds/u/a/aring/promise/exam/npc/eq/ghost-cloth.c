#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
  set_name(HIW+BLK"惡鬼衣"NOR, ({ "ghost cloth","cloth" }) );
  set("long",@long
某大師的著名作品，其名不詳，下落也不詳。
long);      
  set_weight(200);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "件");
    set("material","gold");
    set("value",1000);
  }
  set("armor_prop/int",1);
  set("armor_prop/armor", 4);
  setup();
}

