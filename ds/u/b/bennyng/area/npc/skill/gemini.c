#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me,int cost);
mapping *action = ({
        ([
        "action": "$N身傾向前, 雙掌舉起, 一招「幻朧魔皇拳」擊向$n",
        "damage":                20,
        "attack":                20,
        "attact_type":  "bar",
            "damage_type":  "鎚傷",
        ]),
        ([
        "action": "$N單手舉起向$n發出一招「異次元空間」",
        "damage":                15,
        "dodge" :               -10,
        "attact_type":  "bar",
            "damage_type":  "戳傷",
        ]),
        ([
        "action": "$N兩手交合,一招「魔皇崩裂拳」向\$n面門狂攻起來",
        "damage":                30,
        "attack":                30,
        "attact_type":  "bar",
        "damage_type":  "內傷",
        ]),
        ([
        "action": "$N全力出擊, 一招「教皇粉星拳」凝氣於拳轉身擊向$n",
        "damage":                35,
        "attack":                35,
        "attact_type":  "bar",
        "damage_type":  "'內傷",
        ]),
        ([
        "action": "$N手上一閃, 一記「光速拳」擊向$n",
        "damage":                10,
        "attack":                35,
        "parry" :                20,
        "attact_type":  "bar",
        "damage_type":  "'瘀傷",
        ]),
});
int valid_learn(object me) {    return 1;       }
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
