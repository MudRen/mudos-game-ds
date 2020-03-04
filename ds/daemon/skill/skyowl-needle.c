// �w�k - �ѱ��w�k (skyowl-needle)
// QC by tmr 2007/01/05
// ���ݭn�S��

#include <ansi.h>
inherit SKILL;
inherit SSERVER;

// �H�޹D�{���ӼW�[�����O
int BonusDamage = this_player()->query_skill("acupuncture-cognition")/6;

void show_damage(object me, object target,int damage)
{
    if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
        tell_object(me,HIY"("+damage+")"NOR);
    if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
        tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
    if(wizardp(me) && me->query("env/debug"))
        tell_object(me, HIR"  ("+damage+")\n"NOR);
}

string *parry_msg = ({
                         "�uť���u��v�@�n�M�Q$p��}�F�C\n",
                         "���G�u���v�a�@�n�Q$p�׶}�F�C\n",
                         "���O�Q$n�Τ⤤�L�b�[�}�C\n",
                         "���O$n���l�@���M�Τ⤤�L�b��}�C\n",
                     });

mapping *action = ({
                       ([
                            "action": "$N������A�u"HIW+BLK"���a����"NOR"�v�w�M�X�ۡA$w����Ӱ_�A�¦V$n���ӥh�C",
                            "damage":               2+BonusDamage,
                            "dodge" :               10,
                            "attact_type":  "tec", 
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N�ϥX�u"HIY"�����b��"NOR"�v�A���M����$n����A�⤤��$w�A�r�V$n��h�A",
                            "damage":                4+BonusDamage,
                            "dodge":                -15,
                            "parry" :               -10,
                            "attact_type":  "tec",
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "$N�ϥX�@�ۡu"HIW+BLK"�𭸩Ѥ�"NOR"�v�A�a�_�b�ذ��A���M��$n�����ӤU�A",
                            "damage":                6+BonusDamage,
                            "dodge" :               -10,
                            "parry" :                10,
                            "attact_type":  "tec",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N����@���A�@���u�븨�Q�ڡv�A�⤤$w��$n����ӥh�A",
                            "damage":                8+BonusDamage,
                            "dodge" :               -10,
                            "parry" :                15,
                            "attact_type":  "tec",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N�V��@�D�A�u"HIY"���a�X��"NOR"�v�k��$w�浹����A���M�X�۪���$n����ʬ֥ަӥh�A",
                            "damage":                10+BonusDamage,
                            "dodge" :                20,
                            "parry" :               -20,
                            "attact_type":  "tec",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N�ϥX�u�@�ۤG���v�A���зL�}�A����X�x�ӥk��X�P�A�X$n���j���ɡA$w�w��$n���A�ӥh�A",
                            "damage":                12+BonusDamage,
                            "dodge" :                10,
                            "parry" :               -20,
                            "attact_type":  "tec",
                            "damage_type":  "�A��",
                        ]),

                       ([
                            "action": "$N��ϡu"HIW+BLK"���a����"NOR"�v���$n���A���M�S�@���u"HIC"�����ѻ�"NOR"�v�A$w�ѤU�ӤW��V$n�A",
                            "damage":                14+BonusDamage,
                            "dodge" :                10,
                            "parry" :                10,
                            "attact_type":  "tec",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N���Ⱚ�|, �@�ۡu"HIC"�j�P�i��"NOR"�v�⤤$w�¦V$n�����Y�F�L�h�A",
                            "damage":                16+BonusDamage,
                            "dodge" :                20,
                            "parry" :               -10,
                            "attact_type":  "tec",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N�ϥX�u"HIR"�N���L��"NOR"�v�A���M����$n���e�A����e�N�����դ޶}�ĤH�`�N�A���M�j�ܤ@�n�A$w����ӥh�A",
                            "damage":                18+BonusDamage,
                            "dodge" :               -10,
                            "parry" :               -10,
                            "attact_type":  "tec",
                            "damage_type":  "���",
                        ]),

                   });

int exert(object me, object target, string arg)
{
    object weapon;
    weapon=me->query_temp("weapon");
    if(!weapon)
        return notify_fail("�ϥΤѱ��w�k�����⤤�n���w�C\n");
    if(weapon->query("skill_type")!="needle")
        return notify_fail("�ϥΤѱ��w�k�����⤤�n���w�C\n");

    if(arg=="off" )
    {
        if( me->query_skill_mapped("needle")!="skyowl-needle")
            return notify_fail("�A�èS���ϥΤѱ��w�k�C\n");
        me->map_skill("needle");
        me->map_skill("parry");
        me->reset_action();
        write("�ޯ�[�ѱ��w�k]�w�����C\n");
        return 1;
    }
    if(me->query_skill("needle")<20)
        return notify_fail("�A����¦�w�k��¦�����L�k�ϥΤѱ��w�k�C\n");
    if(me->query("ap")<20 || me->query("hp")<20)
        return notify_fail("�A�����骬�p�L�k�ϥΤѱ��w�k�C\n");

    if(me->query_skill_mapped("needle")=="skyowl-needle")
        return notify_fail("�A���b�ϥΤѱ��w�k�C\n");
	if(!me->skill_active( "skyowl-needle",(: call_other, __FILE__, "delay", me, 6 :), 10))
        return notify_fail("�A���۪��ʧ@�٨S�����C\n");

    me->map_skill("needle", "skyowl-needle");
    me->map_skill("parry", "skyowl-needle");

//    if( me->query("class2") == "skyowl_military" )
    me->reset_action();
    message_vision("\n"HIW"$N�ⴤ"+weapon->name()+HIW"��ݫe�A�}�e�u���N�ߪK�v, �}�l�I�i�y�ѱ��w�k�z�C\n"NOR,me);
    me->receive_damage("ap",5);
    me->start_busy(1);
    return 1;
}

void delay(object me,int cost)
{
    object weapon;
    if(!me)
        return;
    weapon=me->query_temp("weapon");
    if(!weapon)
    {
        me->map_skill("needle");
        me->map_skill("parry");
        me->reset_action();
        return;
    }
    if(weapon->query("skill_type")!="needle")
    {
        me->map_skill("needle");
        me->map_skill("parry");
        me->reset_action();
        return;
    }
    if(me->query_skill_mapped("needle")!="skyowl-needle")
        return;
    if(me->query_skill_mapped("parry")!="skyowl-needle")
        return;

    if(me->query("ap")<7)
    {
        me->map_skill("needle");
        me->map_skill("parry");
        me->reset_action();
        message_vision(HIW"$N����O�����L�k�~��ϥΤѱ��w�k�A�u�n��Τ@��ۦ��C\n"NOR,me);
        return ;
    }
me->skill_active( "skyowl-needle",(: call_other, __FILE__, "delay", me, 6 :), 10);
}

mapping query_action(object me, object target, object weapon)
{
    return action[random(sizeof(action))];
}

string query_parry_msg(object me, object target, object weapon)
{
    return parry_msg[random(sizeof(parry_msg))];
}


int valid_learn(object me)
{
    return 1;
}
int practice_skill(object me)
{
    return 1;
}
