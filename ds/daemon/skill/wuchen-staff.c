#include <ansi.h>
inherit SKILL;
inherit SSERVER;
mapping *action = ({
                       ([
                            "action": "$N���$w�A�@�ѩ_�r�L�Ǫ���l�A�e�O�b���A�r�Y�Y�s�A��$n��$l�r�M���h",
                            "damage":                10,
                            "dodge" :                8,
                            "parry" :                5,
                            "attact_type":  "bio",  // �]�w�ޯ઺��������
                            // ������ �ͪ�(bio) �~��(bar)
                            // �]�k(wit)���F(sou)���(tec)
                            "damage_type":  "ݴ��",
                        ]),

                       ([
                            "action": "$N�⤤$w���Y�@�ϡA�@�ѵL�P�ۤ񪺮�l�A�n�ɦp�Ƥs�ˮ���A�`�a���a�A��$n�e���ӥh",
                            "damage":                8,
                            "dodge":                 -5,
                            "parry" :                12,
                            "attact_type":  "bio",
                            "damage_type":  "����",
                        ]),
                       ([
                            "action": "$N���ίe�p�涳�y���A�⤤$w���ӡA�ۤ��M�ۡA�@�Χ��v�A��n��$n��$l",
                            "damage":                 7,
                            "dodge" :                 9,
                            "parry" :                -6,
                            "attact_type":  "bio",
                            "damage_type":  "ݴ��",
                        ]),

                       ([
                            "action": "$N���v�@�E�A�⤤$w�@�ѫl�����A�e�p�y���A�r�Y�s�Y�A��$n���Y�A��",
                            "damage":                13,
                            "dodge" :                20,
                            "parry" :                -15,
                            "attact_type":  "bio",
                            "damage_type":  "����",
                        ]),

                       ([
                            "action": "$N�⤤$w�~����~�A�@��"HIG"�u�����p�ӡv"NOR"�A��$n��$lŧ�h�A�֯e��F�C",
                            "damage":                15,
                            "dodge" :                -10,
                            "parry" :                13,
                            "attact_type":  "bio",
                            "damage_type":  "ݴ��",
                        ]),
                   });
void delay(object me,int cost);
int exert(object me, object target, string arg)
{
    string msg;
    object weapon;

    weapon=me->query_temp("weapon");
    if(arg=="off" )
    {
        if( me->query_skill_mapped("staff")!="wuchen-staff")
            return notify_fail("�A�èS���ϥεL�Ч��k\n");
        me->map_skill("staff");
        me->reset_action();
        write("�ޯ�[�L�Ч��k]�w�����C\n");
        return 1;
    }
    if(!weapon) return notify_fail("�ϥεL�Ч��k�����⤤�n���ڧ��C\n");
    if(weapon->query("skill_type")!="staff") return notify_fail("�ϥεL�Ч��k�����⤤�n���ڧ��C\n");
    if(me->query_skill_mapped("staff")=="wuchen-staff") return notify_fail("�A���b�ϥεL�Ч��k�C\n");
    if(me->query("ap")<10 || me->query("hp")<10 ) return notify_fail("�A�����骬�p�L�k�ϥεL�Ч��k�C\n");
if(!me->skill_active( "wuchen-staff",(: call_other, __FILE__, "delay", me ,6:), 10))
        return notify_fail("�A�����۰ʧ@�٨S�����C\n");
    me->map_skill("staff", "wuchen-staff");
    me->reset_action();
    message_vision("\n"HIW" $N�\\�e���u�A�����E��A��W"+weapon->name()+"���ͭ��A�}�l�I�i�L�Ч��k�C\n"NOR,me);
    me->receive_damage("ap",5);
    me->start_busy(1);

    //me->start_call_out( (: call_other, __FILE__, "delay", me ,6:), 10);
    return 1;
}


void delay(object me,int cost)
{
    object weapon;
    if(!me) return;
    weapon=me->query_temp("weapon");
    if(!weapon)
    {
        me->map_skill("staff");
        me->reset_action();
        return;
        }
        if(weapon->query("skill_type")!="staff")
        {
            me->map_skill("staff");
            me->reset_action();
            return;
        }
        if(me->query_skill_mapped("staff")!="wuchen-staff")
        {
            return;
        }
        if(me->query("ap")<7)
        {
            me->map_skill("staff");
            me->reset_action();
            message_vision("\n"HIW"$N����O�����L�k�~��ϥεL�Ч��k, �u�n��Τ@��ۦ��C\n"NOR,me);
            return ;

        }
        if( me->is_fighting() ) me->receive_damage("ap",5); //luky
        me->skill_active( "wuchen-staff",(: call_other, __FILE__, "delay", me ,cost:), 10);
}

int valid_learn(object me) {    return 1;       }

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }
