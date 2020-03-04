#include <weapon.h>
#include <ansi.h>
inherit WHIP;

void create()
{
  set_name( "逐日者軟鞭", ({ "sun-follow whip","whip"}) );
    set("long", "逐日者軟鞭是條通體銀白的鞭子，是用非常特殊的材質所做成的，質地非常輕盈。");
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "條");
    set("material", "iron");
    set("value", 1500);
  }
  init_whip(35);
  setup();
}


