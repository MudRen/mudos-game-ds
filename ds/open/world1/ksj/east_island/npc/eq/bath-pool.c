#include <ansi.h>
inherit ITEM;

void create()
{
  set_name("大浴池", ({"bath pool","pool"}));
  set("long",@LONG
一個很大的木造浴池，池子的四周熱騰騰的溫泉正不斷地注入池中，
浴池中有幾個客人正在舒服地泡湯。
LONG
  );
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else
  {
    set("no_get",1);
    set("no_drop",1);
    set("unit", "座");
    set("volume",1000);
    set("value",500);
  }
  setup(); 
}
