#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
  set_name("元氣丸", ({ "genki pill","pill" }));
  set("long",
      "多年前東方島上的村民採集稀有藥物研製成的藥丸，藥效超強。\n"
     );
  set_weight(600);
  if(clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "顆");
  }
  set("value", 3000);
  set("heal",([
      "hp": 1500,
      "ap": 700,
      "mp": 200,
     ]));
  setup();
}
