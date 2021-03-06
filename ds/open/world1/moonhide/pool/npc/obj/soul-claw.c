#include <ansi.h>
#include <weapon.h> 
inherit F_UNIQUE;
inherit FIST;

void create()
{
  set_name(HIC"追魂"NOR , ({ "following-soul claw","claw","soul" }) );
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", "乃是名匠『子黃丹』所打造的，聚集數千遊魂，配合\n"
                "一年裡的所有滿月時間，打造出日月金華的『追魂』[特攻為必中，請注意 Bar 的高低]。\n");
    set("material", "gold");
    set("value",10000);
    set("replica_ob",__DIR__"soul-claw2");
  } 
  set("weapon_prop/str",3);
  set("weapon_prop/dex",-2);
  set("weapon_prop/int",-1);  
  set("weapon_prop/bar",1);
  init_fist(65+random(3));
  setup();
} 

void attack(object me, object victim)
{
    ::attack();
    if(!me) return;
    if(!victim) return;

    if( me->query_skill("unarmed") < 80 ) return;
    if( me->query_str() < 30 ) return;
    if( random(100) < 80 ) return;      /* 20% 的特攻發動率 */

        message_vision(HIB"追魂放出數十條淒厲的鬼魂，在$n"HIB"的體內四處流竄，$n"HIB"受到了內傷！！！\n" NOR, me, victim);
        victim->receive_damage("hp", 10 + random(40), me);      /* 10~49 */
}

