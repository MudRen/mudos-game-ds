#include <weapon.h>
#include <ansi.h>
inherit FORK;
inherit F_UNIQUE;
void create()
{
        set_name(MAG"��]"HIW"��"BLU"�B�H"NOR, ({ "night pike","pike" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
	{
        set("unit", "��");
        set("long","�]�����R�j�A�D�`���աA�����ˤO�j����H�C\n");
        set("value",30000);
	set("no_drop",1);
	set("no_sell",1);
        set("material", "gold");
        set("volume",1);
        }
	set("weapon_prop/bar",3);
	set("weapon_prop/armor",35);
    	set("weapon_prop/str",2);
        set("weapon_prop/dex",3);
    	set("weapon_prop/hit",20);
        init_fork(120,TWO_HANDED);
    	setup();
}
void attack(object me,object victim)
{
        ::attack();
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        if(random(3)) return; // 1/6 �����v�S��
        message_vision(HIR"$N�⤤�����j��M�g�X�@�D�H��C\n"NOR,me);
        COMBAT_D->do_attack(me, victim, this_object(), 4);
        COMBAT_D->report_statue(victim);
        victim->add_busy(1);
        return;
}
int query_autoload() { return 1; }