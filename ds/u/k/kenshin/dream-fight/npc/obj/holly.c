inherit ITEM;
#include <ansi.h>

void create()
{
  set_name("枯\樹枝", ({ "holly"}));
  set("long",@LONG
由樵老所造，可直接飛向東方日出之島(fly)。
LONG);
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "顆");
    set("value", 1000);
    set("no_sell", 1);
    set("no_sac", 1);
  }
  setup();
}

