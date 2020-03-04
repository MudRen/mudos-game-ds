#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
  set_name(HIY"虎骨長杖"HIR"(S)"NOR,({"tiger staff","staff"}));
  set("long",@LONG
劍牙巨虎的腿骨製成的長杖，較一般金鐵更為堅硬。
LONG
);
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_skill",60);
    set("unit", "把");        
    set("value",100000);
    set("volume",3);
    set("weapon_prop/str",1);         
    set("material","steel");       
  }        
  init_staff(48);
  setup();
}

int query_autoload() { return 1; }
