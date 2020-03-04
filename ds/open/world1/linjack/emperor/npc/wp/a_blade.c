#include <weapon.h>
inherit BLADE;
void create()
{
        set_name("快刀", ({ "fast blade", "blade" }) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "這是一把鋒銳的快刀，刀身較短，刀柄纏著厚厚的棉布。\n");
                set("value", 2000);
                set("material", "blacksteel");
                set("wield_msg","$N握起一把快刀。\n");
                set("unwield_msg","$N放下快刀。\n");
                set("limit_skill",40);
                set("limit_con",25);
                set("limit_dex",30);
        }
//    set("weapon_prop/hit",20);
    init_blade(40); // from 50 to 40-tmr
    setup();
}

// 沒必要做特攻 - Tmr 2006/12/01
/*
void attack(object me,object victim)
{
  int a=random(7);
  if(!me || !victim || userp(me) || me->is_busy() || a<4 ) return;
  COMBAT_D->do_attack(me, victim, this_object(), 2);
  if( a < 6 ) return;
  COMBAT_D->do_attack(me, victim, this_object(), 4);
  return;
}
*/
