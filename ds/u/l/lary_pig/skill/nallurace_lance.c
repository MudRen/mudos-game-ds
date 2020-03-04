#include <ansi.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
        ([
        "action": "$N�˫��⤤��$w�ϥX�@���u�Ѫe���a�v�A�j�եѤU�ӤW����\n$n��$l",
        "damage":                20,
        "dodge":                 -5,
        "parry" :                -10,
        "damage_type":  "���",
        ]),

        ([
        "action": "$N���t�����ʸ}�U���B��A�X��$n�@�Ӧ�ʤW���}��ϥX�@���u���S�g�P�١v�A�u��$N�N�⤤\n��$w���W�@����V$n���U�E�A�P���ਭ¶��$n�����ᵹ�P�s�f����\n",
        "damage":                25,
        "dodge":                 10,
        "damage_type":  "����",
        ]),

        ([
        "action": "$N���𾮯��A�N�������O�q���E�ۺj�Y�A�I�i�@���u�Ѧa�T�v�A�u��$N�f���⤤��$w�H�j�P�i�Ͱ�������\n�N$n�����ܰ��ŦA�N�L���������U",
        "damage":                25,
        "dodge" :               -10,
        "parry" :               -10,
        "damage_type":  "����",
        ]),

        ([
        "action": "$N���M�N�j�����\�A�ϥX�@���u�����١v�H��²�檽���A�]�̦��Ī���աA\n�r��$n���U�L",
        "damage":                 15,
        "dodge" :                 -5,
        "parry" :                 -5,
        "damage_type":  "�A��",
        ]),

        ([
        "action": "$N�H�j�������߬����I�ֳt����ʤ⤤��$w�ϥX�@���u�s�����ɡv�A\n�K�����j�աA���s���_���F�V$n�P���n�`",
        "damage":                20,
        "parry" :                 5,
        "damage_type":  "�j��",
        ]),

});

int exert(object me, object target, string arg)
{
        string msg;
        object weapon;
        
        weapon=me->query_temp("weapon");
        if(arg=="off" )
        {
                if( me->query_skill_mapped("fork")!="nallurace_lance")
                        return notify_fail("�A�èS���ϥΨ��|�p���M�h�y�j�k�C\n");
                me->map_skill("fork");
                me->reset_action();
                write("�ޯ�y���|�p���M�h�y�j�k�z�����C\n");
                return 1;
        }
        if(!weapon) return notify_fail("�z�I�Ť�ϥκj�k�I�H�n��]�a��Z���a�C\n");
        if(weapon->query("skill_type")!="fork") return notify_fail("�A���|�{���o��Z����I�i�j�k�a�C\n");
        if(me->query_skill("fork")<10) return notify_fail("���U�I�A����¦�j�N����t�A�ڥ��b���d�o�M�j�k�C\n");
        if(me->query_skill_mapped("fork")=="nallurace_lance")
                return notify_fail("�A���b�ϥΨ��|�p���M�h�y�j�k�C\n");
        if(me->query("mp")<10 || me->query("hp")<10) return notify_fail("�A�����骬�p�L�k�ϥΨ��|�p���M�h�y�C�k�C\n");
        me->map_skill("fork", "nallurace_lance");
        me->reset_action();
        message_vision("\n"HIC" $N���|�⤤��"+weapon->name()+"�A�V���|�p�����ꪺ��V��ӫ��j§�A�}�l�I�i�y���|�p���M�h�y�j�k�z�C\n"NOR,me,target);
        me->add("mp", -4);
        me->start_busy(1);
        call_out("delay",10,me);
        return 1;
}

void delay(object me)
{
        object weapon;
        if(!me) return;
        weapon=me->query_temp("weapon");
        if(!weapon)
        {
                me->map_skill("fork");
                me->reset_action();
                remove_call_out("delay");
                return;
        }
        if(weapon->query("skill_type")!="fork")
        {
                me->map_skill("fork");
                me->reset_action();
                remove_call_out("delay");
                return;
        }
        if(me->query_skill_mapped("fork")!="nallurace_lance")
        {
         remove_call_out("delay");
         return;
        }
        if(me->query("mp")<4)
        {
                me->map_skill("lance");
                me->reset_action();
                message_vision("\n"HIW"$N��O���~�A�L�k�~��I�i���|�p���M�h�y�j�k�A�t�׳v���C�F�U�ӡC\n"NOR,me);
                remove_call_out("delay");
                return ;
        }
        me->add("mp",-4);
        call_out("delay",5,me);
}

int valid_learn(object me) {    return 1;       }
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }