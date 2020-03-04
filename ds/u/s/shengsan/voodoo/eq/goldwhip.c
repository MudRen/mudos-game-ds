
#include <weapon.h>
// 需裝備在 lv64 以上的mob
inherit WHIP;
void create()
{
  set_name("金蛇鞭",({"golden whip","golden","whip"}));
set_weight(32000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "條");
    set("long","這是一條金蛇鞭,曾經在巫毒教出現過。\n");
    set("value",4140);		// value = damage*5 + damage*5*0.15
    set("material", "leather");
    set("wield_msg","$N從腰間取出一條$n\n");
//  set("weapon_prop/parry",2);
    set("weapon_prop/attack",4);
    set("unequip_msg", "$N手中的$n收回至腰際。\n");
set("whip",180);
    init_whip(720);	// damage = skill*n
  }

  setup();

}
