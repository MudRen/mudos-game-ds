#include <weapon.h>
#include <ansi2.h>
inherit SWORD;
void create()
{
        set_name(MAG"月夜"HIW"˙"BLU"分火"NOR, ({ "night sword","sword" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
	{
        	set("unit", "把");
                set("long","神劍分火，化敵為塵。\n");
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
      set("wield_msg","$N從腰間把$n拿在手上，忽然$N周身籠罩著火焰。\n");
      set("unwield_msg", "$N將$n小心的收好。\n");
    	setup();
}
void attack(object me,object victim)
{
        ::attack();
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        if(random(6)) return;        
        message_vision(HIC"分火"HIY"發出一道"HIW"烈焰 , "HIR"讓敵人措手不及。\n"NOR,me);
        COMBAT_D->do_attack(me, victim, this_object(), 5);
        COMBAT_D->report_statue(victim);
        victim->add_busy(1);
        return;
}
int query_autoload() { return 1; }
