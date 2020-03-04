#include <ansi.h>
inherit SKILL;
mapping *action = ({
 ([      "action":               "$N緩緩的走向$n，你的身形忽左忽右，令$n看不清�,
                "dodge":                -50,
                "parry":                -30,
                "force":                100,
                "damage_type":  "瘀傷",
        ]),
 ([      "action":               "$N雙臂一輝，使出七傷拳之"HIW"錐"RED"心刺骨"NO,
                "dodge":                -50,
                "parry":                -50,
                "force":                100,
                "damage_type":  "瘀傷",
        ]),
 ([      "action":               "$N右臂一揮，揚腕一拳打出，施展"HIC"痛"HIY"不",
                "dodge":                -50,
                "parry":                -50,
                "force":                100,
                "damage_type":  "瘀傷",
        ]),
 ([      "action":               "$N逆運真氣至手上少陽三焦經，剛強而炙熱的內勁�,
                "dodge":                -50,
                "parry":                -50,
                "force":                120,
                "damage_type":  "內傷",
        ]),
});
int valid_enable(string usage) { return usage=="unarmed"; }
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

