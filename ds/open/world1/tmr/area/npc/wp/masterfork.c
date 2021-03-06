#include <weapon.h>
#include <ansi.h>
inherit FORK;
inherit F_UNIQUE;
void create()
{
	set_name(HIR"鐵血戰矛"NOR, ({ "blood pike","pike" }) );
	set_weight(18000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","這把長矛桿為紅色, 纓為紫, 霸氣十足。\n");
		set("value",30000);
		set("material", "gold");
		set("volume",6);
        set("replica_ob",__DIR__"dragon-fist");
	}
    set("weapon_prop/str",2);
	set("weapon_prop/dex",-3);
    set("weapon_prop/hit",5);
	init_fork(77,TWO_HANDED);
    setup();
}
void attack(object me,object victim)
{
        ::attack();
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        if(random(6)) return; // 1/6 的機率特攻
	message_vision(HIR"$N手中的鐵血戰矛突然發出一絲紅光..\n"NOR,me);
        COMBAT_D->do_attack(me, victim, this_object(), 4);
	COMBAT_D->report_statue(victim);
	victim->add_busy(1);
        return;
}
