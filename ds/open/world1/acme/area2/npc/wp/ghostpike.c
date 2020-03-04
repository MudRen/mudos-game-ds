#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit FORK;
void create()
{
        set_name(HIM"莫干邪將"NOR, ({ "mo gan she jung","pike","jung","mo","gan","she" }) );
        set_weight(17000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("limit_str",30);
	       set("limit_skill",40);
	       set("limit_lv",20);
               set("unit", "把");
               set("long", "這是把槍相傳是在一百多年前上國初創之時，\n"
                           "妖孽眾多，由某武將揮舞斬殺妖孽所開鋒而成\n"
                           "的槍，裡面藏了一百二十條惡靈，殺敵時威力\n"
                           "驚人。\n");
            set("value",10000);
	       set("volume",6);
               set("material","blacksteel");
	       set("replica_ob",__DIR__"coldpike");
        }
   set_temp("ghost",120);
   set("weapon_prop/hit",-15);
   set("weapon_prop/dodge",-20);
   set("weapon_prop/con",1);
   init_fork(65,TWO_HANDED);
   setup();
}
void attack(object me,object victim)
{
	int damage,dod;
        ::attack();
        if(!me) return;
        if(!victim) return;
	dod=victim->query_int();
	if( dod>100 ) dod = 100;
	if( me->query("ap") < 100 ) return;
	if( this_object()->query_temp("ghost") < 1 ) return;
	if( random(30) < 25 ) return; 
	if( random(me->query_skill("fork",2)) > random(dod) )
	{
                damage = (me->query_damage()/5)+(this_object()->query_temp("ghost"));
                damage = damage - (victim->query_shield()/3) - random(victim->query_shield()/3);
                damage = COMBAT_D->Merits_damage(me,victim,damage,"bar");
                if(damage > 250) damage = 250+random(10);
                victim->receive_damage("hp", damage, me );
                message_vision("\n"
                +MAG"$N手中的莫干邪將突然一陣抖動，出現了"+chinese_number(this_object()->query_temp("ghost"))+"條鬼影殺向$n！\n"NOR
                +HIR"$n被厲鬼纏身，全身上下被抓破數處！\n\n"NOR
                ,me,victim);
		COMBAT_D->report_status(victim);
                me->receive_damage("ap",12);
		this_object()->add_temp("ghost",-1);
                return;
	}
	else
	{
		message_vision("\n"+MAG"$N手中的莫干邪將突然一陣抖動，出現了"+chinese_number(this_object()->query_temp("ghost"))+"條鬼影殺向$n！\n"NOR+
				    HIR+"$n心知不妙，急忙抽身遠退數丈，驚魂未定。\n"NOR,me,victim);
		me->receive_damage("ap",10);
		victim->add_busy(1);
		this_object()->add_temp("ghost",-1);
		return;
	}
}
