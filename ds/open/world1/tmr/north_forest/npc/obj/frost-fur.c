#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(HIW"冰霜軟毛"NOR ,({ "frost-troll fur","fur" }) );
  set("long",@LONG
這是一片從北方大森林的冰霜巨魔取得的軟毛。
LONG
);
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "片");
    set("value", 1000);
  }

  setup();
}

