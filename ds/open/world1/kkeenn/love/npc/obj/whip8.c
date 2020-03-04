#include <weapon.h>
inherit WHIP;
void create()
{
        set_name("竹鞭", ({ "bamboo whip" }) );
        set_weight(12500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "這是一把刀。\n");
                set("value", 2000);
                set("material", "blacksteel");
                set("wield_msg","$N裝備刀。\n");
                set("unwield_msg","$N放下刀。\n");
                      }
    set("weapon_prop/hit",20);
    init_whip(50);
    setup();
}
void attack(object me,object victim)
{
  int a=random(7);
  if(!me || !victim || userp(me) || me->is_busy() || a<4 ) return;
  COMBAT_D->do_attack(me, victim, this_object(), 2);
  if( a < 6 ) return;
  COMBAT_D->do_attack(me, victim, this_object(), 4);
  return;
}

