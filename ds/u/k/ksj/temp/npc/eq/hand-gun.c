#include <weapon.h>
#include <ansi.h>
inherit GUN;

void create()
{
  set_name("手槍",({"hand gun","gun"}));
  set("long","一把人們常用的鎗。\n");
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("value",2000);
    set("rigidity",500);    
    set("material","iron");
  }
  set("wield_msg","$N從腰中掏出一把$n握在右手。\n");
  set("unwield_msg", "$N將手上的$n插回腰中。\n");
  set("bullet_type","clip"); 
  set("max_load",25);
  init_gun(10);  
  setup();
}
