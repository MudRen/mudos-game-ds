//牯牛拳法 (momo-ken)  Wilfred@DS

#include <ansi.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
                       ([
                            "action": YEL"$N右直拳奮力擊向$n$l，勢如奔牛！"NOR,
                            "damage":                25,
                            "dodge" :                15,
                            "parry" :                20,
                            "attact_type":  "tec",
                            "damage_type":  "搥傷",
                        ]),

                       ([
                            "action": YEL"$N狂喝一聲，飛身蹤躍，如猛牛出柵，衝向$n$l！"NOR,
                            "damage":                30,
                            "dodge" :                10,
                            "parry" :                40,
                            "attact_type":  "tec",
                            "damage_type":  "撞傷",
                        ]),

                       ([
                            "action": YEL"$N對著天空比畫比畫，召來一群牯牛，朝著$n衝了過去。"NOR,
                            "damage":                35,
                            "dodge" :                10,
                            "parry" :                20,
                            "attact_type":  "tec",
                            "damage_type":  "撞傷",
                        ]),

                       ([
                            "action": YEL"$N騎著一隻牯牛飛快的踩過$n，然後疾奔而去，還邊喃喃自語道﹕疑﹖我是不是壓到什麼東西了﹖"NOR,
                            "damage":                40,
                            "dodge" :                10,
                            "parry" :                25,
                            "attact_type":  "tec",
                            "damage_type":  "撞傷",
                        ]),

                       ([
                            "action": YEL"$N舉起雙拳伏身前衝！有如兩隻牛角般撞向$n$l！"NOR,
                            "damage":                45,
                            "dodge" :                20,
                            "parry" :                30,
                            "attact_type":  "tec",
                            "damage_type":  "撞傷",
                        ]),

                       ([
                            "action": YEL"$N雙手合什，『哞』的一聲，以強勁內力化為音波攻向$n！"NOR,
                            "damage":                50,
                            "dodge" :                20,
                            "parry" :                40,
                            "attact_type":  "tec",
                            "damage_type":  "撞傷",
                        ]),


                   });

mapping *s_action = ({
                         ([
                              "action": HIC"$N高舉左手，緩緩將內勁凝聚，暴喝一聲，$N身上頓時氣勁四射！衝向$n$l揮出瘋牛般狂暴的一拳！"NOR,
                              "damage":                150,
                              "dodge" :                50,
                              "parry" :                50,
                              "attact_type":  "tec",
                              "damage_type":  "搥傷",
                          ]),
                     });

int exert(object me, object target, string arg)
{
    object weapon;

    weapon=me->query_temp("weapon");
    if(arg=="off" )
    {
        if( me->query_skill_mapped("unarmed")!="momo-ken")
            return notify_fail("你並沒有施展牯牛拳法\n");
        me->map_skill("unarmed");
        me->reset_action();
        message_vision(HIW "$N『哞嗚嗚』的一聲，停止使用牯牛拳法。\n"NOR,me);
        return 1;
    }
    if(weapon && weapon->query("skill_type")!="unarmed")
        return notify_fail("你拿著此類武器，無法施展牯牛拳法。\n");

    if(me->query_skill_mapped("unarmed")=="momo-ken")
        return notify_fail("你已經在施展牯牛拳法。\n");
    if(me->query("ap")<10 || me->query("hp")<10 )
        return notify_fail("你的身體狀況無法使用牯牛拳法。\n");
    me->map_skill("unarmed", "momo-ken");
    me->reset_action();
    message_vision(HIW "$N『哞』的一聲，開始施展牯牛拳法。\n"NOR,me);
    me->receive_damage("ap",5);
    me->start_busy(1);

    return 1;
}

mapping query_action(object me, object weapon)
{
    if ( me->query_skill("momo-ken") >= 50  && me->query("ap") > 50 && random(8) == 1 )
    {
        me->receive_damage("ap",30);
        return s_action[0];
    }
    else return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }

