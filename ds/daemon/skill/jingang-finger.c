// ������]�� jingang-finger.c
// ��������(miao-jian bonze)�{��ޯ�
// By Tmr -2002/01/24-

#include <ansi.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
                       ([
                            "action": "$N�@�ۡu�д��۩ʡv�A���⭹�����E�u�l�A�۪񨭪��I�V$n$l",
                            "damage":                20,
                            "dodge" :                10,
                            "parry" :                15,
                            "attact_type":  "bio",
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "$N�ϥX�֩ۡu�C��ù���v�A���k���Q���A��½��V$n$l",
                            "damage":                30,
                            "dodge" :                10,
                            "parry" :                5,
                            "attact_type":  "bio",
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "$N���E�u�l�A�ϥX�u�j��ù�~�v�A���k������g�X�@�D�u��A���O��V$n$l",
                            "damage":                35,
                            "dodge" :                10,
                            "parry" :                5,
                            "attact_type":  "bio",
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "$N�ϥX�u�������ءv�A�k�⭹���g�X�@�D�u����O��V$n$l�A���⭹�B������H�Y�e�I�V$n����",
                            "damage":                30,
                            "dodge" :                10,
                            "parry" :                5,
                            "attact_type":  "bio",
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "$N�f�Ŧ򸹡A�ϥX������]������" + HIY"�u�C�����v"+ NOR "�A�k�⤭�����ĩ��I������V$n$l",
                            "damage":                50,
                            "dodge" :                10,
                            "parry" :                20,
                            "attact_type":  "bio",
                            "damage_type":  "���",
                        ]),

                   });

int exert(object me, object target, string arg)
{
    object weapon;

    weapon=me->query_temp("weapon");
    if(arg=="off" )
    {
        if( me->query_skill_mapped("unarmed")!="jingang-finger")
            return notify_fail("�A�èS���ϥΡu������]���v�C\n");
        me->map_skill("unarmed");
        me->reset_action();
        write("�ޯ�u������]���v�w�����C\n");
        return 1;
    }
    if(weapon && weapon->query("skill_type")!="unarmed")
        return notify_fail("�A���ۦ����Z���A�L�k�ϥΡu������]���v�C\n");

    if(me->query_skill_mapped("unarmed")=="jingang-finger")
        return notify_fail("�A�w�g�b�ϥΡu������]���v�C\n");
    if(me->query("ap")<10 || me->query("hp")<10 )
        return notify_fail("�A�����骬�p�L�k�ϥΡu������]���v�C\n");
    me->map_skill("unarmed", "jingang-finger");
    me->reset_action();
    message_vision(HIY "$N���⵲�F�Ӧ�L�A���O�u������]���v���_�⦡�C\n"NOR,me);
    me->receive_damage("ap",5);
    me->start_busy(1);

    return 1;
}



mapping query_action(object me, object weapon)
{
    /*
    if ( me->query_skill("awmay-ken") >= 80 
    	&&	me->query("ap") > 500 
    	&& random(30)>=27 )
    {
    	me->receive_damage("ap",30);
    	return s_action[0];
    }
    	else
    		*/
    return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }
