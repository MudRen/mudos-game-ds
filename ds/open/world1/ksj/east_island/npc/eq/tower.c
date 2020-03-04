#include <ansi.h>
inherit ITEM;

void create()
{
  set_name("瞭望臺", ({"tower"}));
  set("long",@LONG
一座用木頭搭建成的高臺，可以看到遠處的情況。
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
