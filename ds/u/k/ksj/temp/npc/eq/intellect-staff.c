#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
  set_name(HIW"智者之杖"NOR,({"intellect staff","staff"}));
  set("long",@LONG
古代智者隨身的木杖，雖然看起來毫不起眼，卻有增強智力與術力的
效用。
LONG
);
  set_weight(1500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_int",50);
    set("unit", "把");        
    set("value",7000);
    set("volume",2);
    set("material","steel");       
  }        
  set("weapon_prop/wit",1);  
  set("weapon_prop/bar",-1);
  set("weapon_prop/int",3);
  init_staff(15);
  setup();
}
