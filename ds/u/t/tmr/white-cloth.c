#include <armor.h>
#include <ansi2.h>
inherit CLOTH;

void create()
{
  set_name(HIW"白紗"NOR ,({ "white-silk cloth","cloth" }) );
  set("long",@LONG
這是一件非常漂亮的白紗禮服，剪栽得體，可以將女人的曼妙
身材全表現出來，是件相當高貴的禮服。
LONG
);
  set_weight(800);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "件");
    set("value", 99999999);
  } 

  setup();
}

int query_autoload() { return 1; }

