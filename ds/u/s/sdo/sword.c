#include <weapon.h>
#include <ansi2.h>
inherit SWORD;
void create()
{
        set_name(MAG"��]"HIW"��"BLU"����"NOR, ({ "night sword","sword" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
	{
        	set("unit", "��");
                set("long","���C�����A�ƼĬ��СC\n");
		set("no_drop",1);
		set("no_sell",1);
                set("material", "gold");
                set("volume",1);
        }
	set("weapon_prop/bar",3);
	set("weapon_prop/armor",35);    	
	set("weapon_prop/str",2);
        set("weapon_prop/dex",2);
    	set("weapon_prop/hit",12);
        init_sword(100);
      set("wield_msg","$N�q�y����$n���b��W�A���M$N�P��Ţ�n�ۤ��K�C\n");
      set("unwield_msg", "$N�N$n�p�ߪ����n�C\n");
    	setup();
}
void attack(object me,object victim)
{
        ::attack();
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        if(random(6)) return;        
        message_vision(HIC"����"HIY"�o�X�@�D"HIW"�P�K , "HIR"���ĤH���⤣�ΡC\n"NOR,me);
        COMBAT_D->do_attack(me, victim, this_object(), 5);
        COMBAT_D->report_statue(victim);
        victim->add_busy(1);
        return;
}
int query_autoload() { return 1; }
