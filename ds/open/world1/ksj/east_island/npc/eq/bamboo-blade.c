#include <weapon.h>
inherit BLADE;

void create()
{
  set_name("袋竹刀", ({ "bamboo blade","blade" }) );
  set("long",@long
用整枝竹子縱向劈成數條，再裝進細長的皮袋內，如此在練習時就
不會傷人了。
long);      
  set_weight(880);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("material", "wood");
    set("value",100);
    set("volume",2);
  }
  init_blade(3);
  setup();
}
