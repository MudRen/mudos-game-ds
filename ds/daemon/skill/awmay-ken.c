//�Ʊ����k (awmay-ken) by tmr Sat Jan 1 2000

#include <ansi.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
                       ([
                            "action": "$N�@�ۡu�a�Q��ȡv�A�����k�W���U����$n$l",
                            "damage":                20,
                            "dodge" :                10,
                            "parry" :                15,
                            "attact_type":  "bio",
                            "damage_type":  "ݴ��",
                        ]),
                       ([
                            "action": "$N�k���b$n���e�@�̡A�����@�ۡu�������K�v���V$n$l",
                            "damage":                25,
                            "dodge" :                5,
                            "parry" :                20,
                            "attact_type":  "bio",
                            "damage_type":  "����",
                        ]),
                       ([
                            "action": "$N�~�a�����V��$n��$l�n�`�֧𤻮��A���O�@�ۡu���᤻�X�v",
                            "damage":                25,
                            "dodge" :                10,
                            "parry" :                20,
                            "attact_type":  "bio",
                            "damage_type":  "����",
                        ]),
                       ([
                            "action": "$N�@�ۡu�������v�A�k�u�b�ݫe��F�ư�A�����~�a�Ѱ�l���X���V$n$l",
                            "damage":                20,
                            "dodge" :                10,
                            "parry" :                10,
                            "attact_type":  "bio",
                            "damage_type":  "����",
                        ]),

                       ([
                            "action": "$N���k�⮱�@�ۡu�t�����v�v�����V$n��$l�n�`",
                            "damage":                20,
                            "dodge" :                5,
                            "parry" :                5,
                            "attact_type":  "bio",
                            "damage_type":  "����",
                        ]),

                       ([
                            "action": "$N�I�i�֩ۡu���m��ӡv�A�����@�����V��$n��F�Q�K���I",
                            "damage":                25,
                            "dodge" :                5,
                            "parry" :                20,
                            "attact_type":  "bio",
                            "damage_type":  "����",
                        ]),


                   });

mapping *s_action = ({
                         ([
                              "action":
                              HIW "���M�}�}����q$N�����_�X�A���O�Ʊ����k�̱j�@�ۡu�ƴH�ѤU�v�I\n\n"
                              +   "\t$N���S�H���A��ոU�d�����@�����V$n$l" NOR,
                              "damage":                120,
                              "dodge" :                30,
                              "parry" :                30,
                              "attact_type":  "bio",
                              "damage_type":  "����",
                          ]),
                     });

int exert(object me, object target, string arg)
{
    string msg;
    object weapon;

    weapon=me->query_temp("weapon");
    if(arg=="off" )
    {
        if( me->query_skill_mapped("unarmed")!="awmay-ken")
            return notify_fail("�A�èS���I�i�Ʊ����k\n");
        me->map_skill("unarmed");
        me->reset_action();
        write("�ޯ�[�Ʊ����k]�w�����C\n");
        return 1;
    }
    if(weapon && weapon->query("skill_type")!="unarmed")
        return notify_fail("�A���ۦ����Z���A�L�k�I�i�Ʊ����k�C\n");

    if(me->query_skill_mapped("unarmed")=="awmay-ken")
        return notify_fail("�A�w�g�b�I�i�Ʊ����k�C\n");
    if(me->query("ap")<10 || me->query("hp")<10 )
        return notify_fail("�A�����骬�p�L�k�ϥζƱ����k�C\n");
    me->map_skill("unarmed", "awmay-ken");
    me->reset_action();
    message_vision(HIW "$N�����~�a�����@�}�����A�}�l�I�i�F�Ʊ����k�I�I�C\n"NOR,me);
    me->receive_damage("ap",5);
    me->start_busy(1);

    return 1;
}



mapping query_action(object me, object weapon)
{
    if ( me->query_skill("awmay-ken") >= 80  && me->query("ap") > 500 && random(30)>=27 )
    {
        me->receive_damage("ap",30);
        return s_action[0];
    }
    else
        return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }
