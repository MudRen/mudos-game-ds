/* aerial-dagger �ƴ��P�k
 * advanced thief �����ޯ�
 * By Tmr 2002/04/04
 */
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
mapping *action = ({
                       ([
                            "action": "$N����⤤$w�ϥX�u�ϫB�j���v�A�q�t�@���ױ״�$n"NOR"��$l��h",
                            "damage":                10,
                            "dodge" :                8,
                            "parry" :                5,
                            "attact_type":  "bio",
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "$N���X�⤤$w�ϥX�@�ۡu���������v�A��խY���Y�{�A���G����$n"NOR"��$l��h",
                            "damage":                8,
                            "dodge" :                8,
                            "parry" :                5,
                            "attact_type":  "bio",
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "$N�⤤$w"NOR"�P�W�{�{�A�a�_�@�ۡu�]���R���v�X$n"NOR"�S�X�}��A��V$n"NOR"��$l��h",
                            "damage":                12,
                            "dodge" :                8,
                            "parry" :                5,
                            "attact_type":  "bio",
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "$N�ϥX�u���̬ݪ�v��̤�W$w�ƤU�A�X$n"NOR"���ߤ��ڡA�r�a��V$n"NOR"��$l��h",
                            "damage":                12,
                            "dodge" :                8,
                            "parry" :                5,
                            "attact_type":  "bio",
                            "damage_type":  "���",
                        ]),
                   });
void delay(object me,int cost);
int exert(object me, object target, string arg)
{
    object weapon;

    weapon=me->query_temp("weapon");
    if(arg=="off" )
    {
        if( me->query_skill_mapped("dagger")!="aerial-dagger")
            return notify_fail("�A�èS���ϥΡu�ƴ��P�k�v\n");
        me->map_skill("dagger");
        me->reset_action();
        write("�ޯ�u�ƴ��P�k�v�w�����C\n");
        return 1;
    }
    if(!weapon)
        return notify_fail("�A�����˳ƤP�����Z���C\n");
    if(weapon->query("skill_type")!="dagger")
        return notify_fail("�A�����˳ƤP�����Z���C\n");
    if(me->query_skill_mapped("dagger")=="aerial-dagger")
        return notify_fail("�A�w�g���b�I�i�u�ƴ��P�k�v�F�C\n");
    if(me->query("ap")<10 || me->query("hp")<10 )
        return notify_fail("�A�ثe�����骬�p���n�C\n");

    me->map_skill("dagger", "aerial-dagger");
    me->reset_action();
      message_vision(HIW"$N�������N�⤤"+weapon->name()+HIW"��̴X�ۡA�}�l�I�i�u�ƴ��P�k�v�C\n"NOR,me);
    me->receive_damage("ap",5);
    me->start_busy(1);

    return 1;
}

int valid_learn(object me) {    return 1;       }

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }

