#include <armor.h>
inherit LEGGING; 
void create()
{
  set_name( "黑武脛甲" , ({"black leggings","leggings"}));
  set("long", @LONG 
這是一件黑沉沉的脛甲，使用一整大塊的生鐵做成，只以生牛皮繫著。
LONG);
  set_weight(1500);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "件");
    set("volume", 1);
    set("value", 3000);
    set("material","iron");
  }
  set("limit_lv",20 );
  set("armor_prop/shield",10 );
  set("armor_prop/con", 1);
  setup();
}

