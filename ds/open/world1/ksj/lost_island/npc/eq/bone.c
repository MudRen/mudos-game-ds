#include <ansi.h>
#include <path.h>
inherit ITEM;

void create()
{
  set_name(HIW"一堆白骨"NOR, ({"bone"}));
  set("long",@LONG
一堆動物的白骨，堆在一旁像小土丘一樣高，看了令人直發毛。
LONG
);
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("no_get",1);
    set("no_drop",1);
    set("unit", "堆");
    set("volume",1000);
    set("value",500);
  }
  setup(); 
}
