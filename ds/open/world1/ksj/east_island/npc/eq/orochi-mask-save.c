#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
    set_name(HIR"真"HIW"•"NOR"八歧"HIC"鱗面"NOR,({"orochi mask","mask"}) );
  set("long",@LONG
取自八歧大蛇頷部的鱗皮製成的面具，柔軟堅韌，散發出強大的邪力
。
LONG);
  set_weight(700); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_con",30);
    set("unit", "張");       
    set("value",7000);          
    set("volume", 2);                       
    set("material", "leather");   
  }
  set("limit_lv",35);
  set("armor_prop/armor",10);
  set("armor_prop/shield",10);
  setup();
}

int query_autoload() { return 1; }
