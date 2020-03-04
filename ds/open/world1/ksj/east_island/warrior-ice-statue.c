#include <ansi.h>
#include <path.h>
inherit ITEM;

void create()
{
  set_name(HIC"武人冰像"NOR, ({"warrior ice statue","statue"}) );
  set("long",@LONG
一座高大的冰塊，冰塊中是一位壯碩的中年武者，從他腰間的長刀並
未出鞘看來，應是促不及防之下遭到冰封，冰塊外圍正在慢慢融化，
不過照這種速度看來沒有十幾二十年是融化不完的。
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
