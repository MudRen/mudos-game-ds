#include <path.h>
inherit ITEM;

void create()
{
  set_name("新陰流皆傳免許\印狀", ({"master credential","credential"}) );
  set("long", 
"承認劍術修練達到最高境界的證明書。\n"
);
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "張");
    set("volume",1);
    set("no_sell",1);
  }
  setup(); 
}
