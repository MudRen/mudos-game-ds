//���aeq���k (keq) ���ժ� Wilfred@DS

#include <ansi.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
                       ([
                            "action": YEL"$N��keq���k���V$n$l"NOR,
                            "damage":                25,
                            "dodge" :                15,
                            "parry" :                20,
                            "attact_type":  "durable",    // ���� ���a eq
                            "damage_type":  "ݴ��",
                        ]),

                   });

int exert(object me, object target, string arg)
{
    string msg;
    object weapon;

    weapon=me->query_temp("weapon");
    if(arg=="off" )
    {
        if( me->query_skill_mapped("unarmed")!="keq")
            return notify_fail("�A�èS���I�ikeq���k\n");
        me->map_skill("unarmed");
        me->reset_action();
        message_vision(HIW "$N����ϥ�keq���k�C\n"NOR,me);
        return 1;
    }
    if(weapon && weapon->query("skill_type")!="unarmed")
        return notify_fail("�A���ۦ����Z���A�L�k�I�ikeq���k�C\n");
    if(me->query_skill_mapped("unarmed")=="keq")
        return notify_fail("�A�w�g�b�I�ikeq���k�C\n");
    me->map_skill("unarmed", "keq");
    me->reset_action();
    message_vision(HIW "$N�}�l�I�ikeq���k�C\n"NOR,me);

    return 1;
}

mapping query_action(object me, object weapon)
{  return action[random(sizeof(action))]; }

int practice_skill(object me) { return 1; }
