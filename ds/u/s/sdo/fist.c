#include <weapon.h>
#include <combat.h>
#include <ansi.h>
inherit FIST;
void create()
{
        set_name(MAG"月夜"HIW"˙"BLU"烈神"NOR, ({ "night fist","fist" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "副");
                set("long", @LONG
這是一雙深黑色的拳套，擁有驚人的殺傷力，讓裝備者擁有逼近神的
力量。而且因為受『夜』的影響，讓它也擁有一些防禦力。
[可儲存裝備]
LONG
);
                set("no_sell",1);
                set("no_sac",1);
		set("no_drop",1);
                set("material", "iron");
        	}
    set("weapon_prop/bar",2);
    set("weapon_prop/hit",10);
    set("weapon_prop/parry",12);
    set("weapon_prop/armor",20);
    set("weapon_prop/shield",2);
    init_fist(60);
    setup();
}

void attack(object me,object victim)
{
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        if(random(2)) return; // 1/3 的機率連攻
        COMBAT_D->do_attack(me, victim, this_object(), TYPE_REGULAR);
        return;
}

int query_autoload() { return 1; }
