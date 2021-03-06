#include <ansi.h>
#include <weapon.h>
inherit BLADE;
inherit F_UNIQUE;
void create()
{
	set_name("狂刀•濁世", ({ "the crazy blade","blade" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "此刀霸氣剛烈, 且仔細觀察便會發現此刀周圍都有一股\n"
                            "煞氣纏繞, 眼尖者可感覺到刀身泛黑, 除此之外, 此刀鋒利\n"
                            "無比, 刀刃又成鋸齒波浪狀, 殺傷力十分驚人, 算是萬中無\n"
                            "一的好刀.\n"
                         );
		set("value", 7500);
		set("material","steel");
		set("limit_skill",50);
		set("limit_dex",25);
                set("wield_msg",MAG"\n$N由刀閘中抽出濁世之刀, 瞬間一陣煞氣四散!\n\n"NOR);
                set("unwield_msg",CYN"\n$N將濁世之刀小心放回刀閘之中.\n\n"NOR);
		set("replica_ob",__DIR__"blade2");
	}
    set("weapon_prop/str",2);
    init_blade(60);
    setup();
}

void attack(object me,object victim)
{
        ::attack();
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        if(random(3)) return; // 1/3的機率出現特攻
        message_vision(HIM"$N手中的濁世之刀突然一道煞氣殺向$n而去，"NOR,me,victim);
        if(me->query("dex") + random(me->query_skill("blade")) > 
           (victim->query("dex")*2/3) + random(me->query_skill("dodge")/2) ) {
        message_vision(HIY"擾亂了$N的步伐!\n"NOR,victim);
                victim->add_busy(1+random(2));
	}
        else message_vision(CYN"但被$N急忙的避開了。\n"NOR,victim);
        me->receive_damage("ap",18+random(10));
        return;
}
