#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
  set_name(HIY"虎尾長鞭"HIR"(S)"NOR,({"tiger whip","whip"}));
  set("long",@LONG
劍牙巨虎的尾巴製成的長鞭，強韌而耐用。
LONG
);
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_skill",60);
    set("unit", "把");        
    set("value",100000);
    set("volume",3);
    set("weapon_prop/str",1);         
    set("material","fur");       
  }        
  init_whip(43);
  setup();
}

int query_autoload() { return 1; }
