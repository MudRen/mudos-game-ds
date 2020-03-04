#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
  set_name( HIR "屍仙戒" NOR,({"unquiet ring","ring"}));
  if( clonep() ) set_default_object(__FILE__);
  else
  {
    set("long",@LONG
這是一枚由無寧屍仙王身上取得的屍仙戒，這戒指是由蟲膠
凝結而成，其實也就是屍仙的精氣所在。
LONG
);
    set("value",10000); 
    set_weight(1000); 
    set("material","diamond");
    set("unit","只");
  } 
  set("armor_prop/wit", 1);   
  set("armor_prop/bio", -1);
  set("armor_prop/int", 2);
  set("armor_prop/armor", 10);
  set("armor_prop/shield", 10);
  setup();
}

