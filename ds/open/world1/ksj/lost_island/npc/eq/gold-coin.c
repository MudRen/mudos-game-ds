#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(HIY"古金幣"NOR,({"gold coin","coin"}));
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","古代製作的金幣，純度稍差了點。");
    set("unit", "堆");
    set("volume",1);
    set("value",5000);
  }
  setup();
}
