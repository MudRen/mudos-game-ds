#include <weapon.h>
inherit WHIP;
void create()
{
        set_name("���@", ({ "bamboo whip" }) );
        set_weight(12500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�o�O�@��M�C\n");
                set("value", 2000);
                set("material", "blacksteel");
                set("wield_msg","$N�˳ƤM�C\n");
                set("unwield_msg","$N��U�M�C\n");
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

