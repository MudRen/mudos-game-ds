//�������k (momo-ken)  Wilfred@DS

#include <ansi.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
                       ([
                            "action": YEL"$N�k�����ĤO���V$n$l�A�զp�b���I"NOR,
                            "damage":                25,
                            "dodge" :                15,
                            "parry" :                20,
                            "attact_type":  "tec",
                            "damage_type":  "ݴ��",
                        ]),

                       ([
                            "action": YEL"$N�g�ܤ@�n�A�������D�A�p�r���X�]�A�ĦV$n$l�I"NOR,
                            "damage":                30,
                            "dodge" :                10,
                            "parry" :                40,
                            "attact_type":  "tec",
                            "damage_type":  "����",
                        ]),

                       ([
                            "action": YEL"$N��ۤѪŤ�e��e�A�l�Ӥ@�s�����A�µ�$n�ĤF�L�h�C"NOR,
                            "damage":                35,
                            "dodge" :                10,
                            "parry" :                20,
                            "attact_type":  "tec",
                            "damage_type":  "����",
                        ]),

                       ([
                            "action": YEL"$N�M�ۤ@���������֪���L$n�A�M��e�b�ӥh�A������ۻy�D�R�áS�ڬO���O���줰��F��F�S"NOR,
                            "damage":                40,
                            "dodge" :                10,
                            "parry" :                25,
                            "attact_type":  "tec",
                            "damage_type":  "����",
                        ]),

                       ([
                            "action": YEL"$N�|�_�����񨭫e�ġI���p�Ⱖ�����뼲�V$n$l�I"NOR,
                            "damage":                45,
                            "dodge" :                20,
                            "parry" :                30,
                            "attact_type":  "tec",
                            "damage_type":  "����",
                        ]),

                       ([
                            "action": YEL"$N����X���A�y�N�z���@�n�A�H�j�l���O�Ƭ����i��V$n�I"NOR,
                            "damage":                50,
                            "dodge" :                20,
                            "parry" :                40,
                            "attact_type":  "tec",
                            "damage_type":  "����",
                        ]),


                   });

mapping *s_action = ({
                         ([
                              "action": HIC"$N���|����A�w�w�N���l���E�A�ɳܤ@�n�A$N���W�y�ɮ�l�|�g�I�ĦV$n$l���X�Ƥ���g�ɪ��@���I"NOR,
                              "damage":                150,
                              "dodge" :                50,
                              "parry" :                50,
                              "attact_type":  "tec",
                              "damage_type":  "ݴ��",
                          ]),
                     });

int exert(object me, object target, string arg)
{
    object weapon;

    weapon=me->query_temp("weapon");
    if(arg=="off" )
    {
        if( me->query_skill_mapped("unarmed")!="momo-ken")
            return notify_fail("�A�èS���I�i�������k\n");
        me->map_skill("unarmed");
        me->reset_action();
        message_vision(HIW "$N�y�N���z���@�n�A����ϥά������k�C\n"NOR,me);
        return 1;
    }
    if(weapon && weapon->query("skill_type")!="unarmed")
        return notify_fail("�A���ۦ����Z���A�L�k�I�i�������k�C\n");

    if(me->query_skill_mapped("unarmed")=="momo-ken")
        return notify_fail("�A�w�g�b�I�i�������k�C\n");
    if(me->query("ap")<10 || me->query("hp")<10 )
        return notify_fail("�A�����骬�p�L�k�ϥά������k�C\n");
    me->map_skill("unarmed", "momo-ken");
    me->reset_action();
    message_vision(HIW "$N�y�N�z���@�n�A�}�l�I�i�������k�C\n"NOR,me);
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
