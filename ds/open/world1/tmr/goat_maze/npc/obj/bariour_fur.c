#include <ansi.h>
inherit ITEM;

void create()
{
  set_name( "半羊人軟毛" ,({ "bariour fur","fur" }) );
  set("long",@LONG
這是一片從羊男的迷宮中的半羊人取來的軟毛。
LONG
);
  set_weight(10);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "片");
    set("value", 10);
  }

  setup();
}


