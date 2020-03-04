// 更新日期: 2003.06.14	修改人: Shengsan@ms2.url.com.tw 修改代號: sV1
#include <ansi2.h>
#include <weapon.h>
inherit FORK;
inherit F_UNIQUE;
void create()
{
        set_name(HIY"英雄長槍"NOR,({"hero pike","pike"}) );
        set("long",@LONG
英雄長槍是無名英雄最稱手的武器了。在戰場上衝鋒陷陣，殺敵將領
於萬軍之中，它和無名英雄一起建立了不少傳說，不過因為沾血過多
，似乎已經帶有一些殺氣。
LONG
	);
        set_weight(25000);
        if (clonep() )
        	set_default_object(__FILE__);
        else 
	{
        set("unit","桿");
        set("value",17000);
        set("volume",5);
        set("material","steel");
//init_fork(62);
        set("replica_ob",__DIR__"long_pike");
   	}
        set("weapon_prop/bar",1);
        set("weapon_prop/bio",-1);//sV1
init_fork(62);
        setup();
}
void attack(object me,object victim)
{
        ::attack();
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        if(random(10)) return; // 1/5 的機率特攻
        message_vision(HIW"$N旋轉著手中的英雄長槍，發出的音波讓敵人頭昏腦脹。\n"NOR,me);
        COMBAT_D->do_attack(me, victim, this_object(), 4);
        COMBAT_D->report_statue(victim);
        victim->add_busy(2);
        return;
}
