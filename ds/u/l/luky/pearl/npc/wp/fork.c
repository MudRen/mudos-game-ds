#include <ansi.h>
#include <weapon.h>
inherit SPEAR;
void create()
{
set_name("叉子",({"fork"}));
set_weight(12200);
if( clonep() )
    set_default_object(__FILE__);
  else {
set("long","\n
這是一支很常見的不鏽鋼叉子。\n");
set("unit", "支");
set("spear",35); //skill 70
set("value",1100);
       }
      setup();
}
