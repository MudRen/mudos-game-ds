#include <armor.h>
inherit NECK;

void create()
{
  set_name("鐵衣護頸",({"iron-cloth neck","neck"}) );
  set("long",@LONG
一條鐵製的護頸，靠近脖子的內層用細鐵線織成，外層則是嵌滿小鐵
片，提供頸部很好的防護。
LONG);
  set_weight(1500); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "件");
    set("value",3000);          
    set("volume", 2);                       
    set("material", "steel");
  }
  set("limit_con",20);
  set("armor_prop/armor",10);       
  setup();
}
