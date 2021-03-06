// tenken.c
#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "action":               "$N奮力耀起﹐右拳勾出一記強勁的"HIG"「昇龍破」"NOR"﹐擊向$n的$l﹗\n",
                "damage":                30,
                "dodge":                -30,
                "parry":                -30,
//                "force":                260,
                "damage_type":  "毆傷"
        ]),
        ([      "action":               "$N倏地一招轉身側踢﹐"HIC"「飛燕疾風腳」"NOR"直逼$n$l﹗\n",
                "damage":                30,
                "dodge":                -30,
                "parry":                -30,
//                "force":                240,
                "damage_type":  "瘀傷"
        ]),
        ([      "action":               "$N身子微斜﹐隨即跨出一步﹐快腿如閃電般地擊出"HIB"「幻影腳」"NOR"﹐瘋狂地襲往$n﹗\n",
                "damage":                40,
                "dodge":                -40,
                "parry":                -40,
//                "force":                220,
                "damage_type":  "瘀傷"
        ]),
        ([      "action":               "$N大喝:"HIW"「接我一記憤怒的鐵拳﹗」"NOR"﹐猛拳直對$n的$l搥去﹗\n",
                "damage":                20,
                "dodge":                -20,
                "parry":                -20,
//                "force":                240,
                "damage_type":  "抓傷"
        ]),
        ([      "action":               "$N瘋狂擊出"HIM"「斬烈拳」"NOR"﹐只見無數猛烈的拳影不停重擊$n﹗\n",
                "damage":                40,
                "dodge":                -40,
                "parry":                -40,
//                "force":                250,
                "damage_type":  "毆傷"
        ]),
        ([      "action":               "$N大吼:"HIR"「地獄大車輪」"NOR"﹐凌空躍起﹐如饑餓的猛獸般撲向$n﹗\n",
                "damage":                50,
                "dodge":                -50,
                "parry":                -50,
//                "force":                280,
                "damage_type":  "摔傷"
        ]),
        ([      "action":               "$N右手騰空一劃﹐一招狂猛的"HIY"「虎煌拳」"NOR"呼嘯而出﹐奔向$n﹗\n",
                "damage":                30,
                "dodge":                -30,
                "parry":                -30,
//                "force":                300,
                "damage_type":  "震傷"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("鋼鐵格鬥技是活動四肢的體術，要徒手才能練習。\n");
        return 1;
}

int valid_enable(string usage) { return usage=="unarmed"|| usage=="parry"; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("hp") < 50 )
                return notify_fail("你的體力(ＨＰ)負荷不了，休息一下再練吧。\n");
        if( (int)me->query("sp") < 10 )
                return notify_fail("你的鬥氣能量(ＳＰ)快耗盡了，休息一下再練吧。\n");
        me->receive_damage("hp", 50);
        me->add("sp", -10);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 100 ) return 0;

        if( random(damage_bonus/2) > victim->query_str() ) {
                victim->receive_wound("hp", (damage_bonus - 100) / 2 );
                switch(random(3)) {
                        case 0: return "你聽到「喀啦」一聲輕響﹐竟似是骨碎的聲音﹗\n";
                        case 1: return "$N勁力一吐﹐$n的$l發出「喀」地一聲爆響﹗\n";
                        case 2: return "只聽見$n的$l「喀」地一聲 ...\n";
                }
        }
}
