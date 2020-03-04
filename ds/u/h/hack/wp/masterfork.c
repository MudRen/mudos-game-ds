#include <weapon.h>
#include <ansi.h>
inherit FORK;
inherit F_UNIQUE;
void create()
{
	set_name(HIR"�K��ԥ�"NOR, ({ "blood pike","pike" }) );
	set_weight(18000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","�o����ٱ쬰����, �լ���, �Q��Q���C\n");
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
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        if(random(6)) return; // 1/6 �����v�S��
	message_vision(HIR"$N�⤤���K��ԥ٬�M�o�X�@������..\n"NOR,me);
        COMBAT_D->do_attack(me, victim, this_object(), 4);
	COMBAT_D->report_statue(victim);
	victim->add_busy(1);
        return;
}
