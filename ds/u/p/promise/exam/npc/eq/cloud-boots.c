#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
  set_name(HIG"踏雲"NOR"奔日靴"NOR, ({ "cloud boots","boots" }) );
  set("long",@long
某大師的著名作品，其名不詳，下落也不詳。
long);      
  set_weight(900);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "雙");
    set("material","gold");
    set("value",3000);
  }
  set("armor_prop/dodge",5);
  set("armor_prop/int",2);
  set("armor_prop/con",2);

  set("armor_prop/dex",2);
  set("armor_prop/armor", 16);
  setup();
}

