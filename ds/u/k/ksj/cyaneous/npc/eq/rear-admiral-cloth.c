#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
  set_name(HIC"少將軍服"NOR ,({"rear admiral cloth","cloth" }) );
  set("long",@LONG
海軍少將的軍服，上面有少將的階級標示，衣服的質料相當的好。
LONG
);
  set_weight(1500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "件");
    set("value",8000);
    set("material", "fur");
    set("limit_con",30);
    set("armor_prop/shield",3);
    set("armor_prop/con",1);
    set("armor_prop/armor", 15);
  }
  setup();
}
