#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me);
void superpower(object me,object target,int z,int damage);
mapping *action = ({
                       ([
                            "action": "$N���ۻy���� :�y�@�M�z�i�ٯ}�s�e�G�j�A�⤤��$w�H�ۥy�l�ܤơA��V$n���ݳ� ",
                            "damage":                20,
                            "dodge" :               -10,
                            "parry" :               10,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "$N���ۻy���� :�y�G���z�i����F�s���j�A�⤤��$w�H�ۥy�l�ܤơA��V$n���Y��",
                            "damage":                20,
                            "dodge" :               -10,
                            "parry" :               10,
                            "attact_type":  "bar",
                            "damage_type":  "����",
                        ]),
                       ([
                            "action": "$N���ۻy���� :�y�T�_�z�i�_�����ƻ�j�A�⤤��$w�H�ۥy�l�ܤơA��V$n���ӳ�",
                            "damage":                20,
                            "dodge" :                -10,
                            "parry" :                10,
                            "attact_type":  "bar",
                            "damage_type":  "�ζ�",
                        ]),
                       ([
                            "action": "$N���ۻy���� :�y�|�A�z�i�s���۪��j�A�⤤��$w�H�ۥy�l�ܤơA��V$n���ⳡ",
                            "damage":                20,
                            "dodge" :               -10,
                            "parry" :                10,
                            "attact_type":  "bar",
                            "damage_type":  "�ζ�",
                        ]),
                       ([
                            "action": "$N���ۻy���� :�y����z�i�Щئʦa���j�A�⤤��$w�H�ۥy�l�ܤơA��V$n���}��",
                            "damage":                20,
                            "dodge" :                -10,
                            "parry" :                15,
                            "attact_type":  "bar",
                            "damage_type":  "�A��",
                        ]),
                   });
int exert(object me, object target, string arg)
{
    int sk,damage;
    object weapon;
    mapping type;
    sk=me->query_skill("killingdragon-yet blade");
    weapon=me->query_temp("weapon");
    if( me->is_ghost() ) return notify_fail("�A�n�F�� ?\n");
    if (!weapon) return notify_fail("�u�}�s��-�����v�ݭn�ΤM...���ϥX�C\n");
    if(weapon->query("skill_type")!="blade") return notify_fail("�A��W���۪F����ϥX�u�}�s��-�����v�C\n");
    if(arg=="off" )
    {
        if( me->query_skill_mapped("blade")!="killingdragon-yet blade")
            return notify_fail("�A�èS���ϥΡu�}�s��-�����v�C\n");
        me->map_skill("blade");
        me->reset_action();
        write("�u�}�s��-�����v�w����ϥΡC\n");
        return 1;
    }

    if(me->query_skill("killingdragon-yet blade")<2) return notify_fail("�[�o ! ! �A train  �@���u�}�s��-�����v�C\n");
    if(me->query("ap")<1 || me->query("hp")<50) return notify_fail("�A������L�k�~��t��u�}�s��-�����v�F�C\n");


    //�ĤG��exert
    if(me->query_skill_mapped("blade")=="killingdragon-yet blade")
    {
        if( me->is_ghost() ) return notify_fail("�A�n�F�� ?\n");
        if( !target ) target = offensive_target(me);
        if (!me->is_fighting())
            return notify_fail("�A���b�ϥΡu�}�s��-�����v�F�C\n");
        if (me->query_skill("killingdragon-yet blade") < 50)
            return notify_fail("�A�ثe���u�}�s��-�����v�A�|����F�u�s��ѤU�v���ҬɡC\n");
        if(me->query("ap")<30)
            return notify_fail("�A�����l�����A�L�k�ϥX�u�s��ѤU�v�C\n");
        if(!me->can_fight(target)) return me->can_fight(target);
        if(!me->is_fighting(target) ) return notify_fail("�A�èS���b�԰��C\n");
        message_vision(BLU"�@�}�I�R . . . . . . . �C\n\n"NOR,me);
        me->receive_damage("ap",10+random(40));
        me->start_busy(2);
        call_out("superpower",1,me,target,1,damage);
        return 1;
    }

if(!me->skill_active( "killingdragon-yet blade",(: call_other, __FILE__, "delay", me ,5:), 10)) return notify_fail("�A���ʧ@�٨S�����C\n");
    me->map_skill("blade", "killingdragon-yet blade");
    me->reset_action();
    message_vision("\n"HIY"$N�H���s����A�B���"+weapon->query("name")+HIC"�}�}�s�u���y�j�T
                   �B�_�F�u�}�v
                   �u�s�v
                   �u�١v
                   �u���v
                   �u���v�C\n"NOR,me);
    me->receive_damage("ap",15);
    me->start_busy(2);
    //      me->start_call_out( (: call_other, __FILE__, "delay", me ,5:), 10);
    return 1;
}
void superpower(object me,object target,int z,int damage)
{
    string msg;
    if(!target) target = offensive_target(me);
    if(!target) return;
    if(!me) return ;
    if(!me->is_fighting()) return;
    if( environment(me) != environment(target) ) return;
    if(!me->is_fighting(target)) me->kill_ob(target);

    z=me->query_skill("killingdragon-yet-blade");
    msg +=HIW"���M$N�����o���A���ߩw������⤤���M"NOR"�A\n";
    msg +=HIR"�@�}���z ! ! ! ! ! �C�����s���Q�ӥX�A��¶�ۤC�رm�� ! ! \n"NOR;
    msg +=HIY"�@���u�s��ѤU�v�A�a���$N���V$n!!\n"NOR;
    message_vision(msg, me, target);

    if( z > random(target->query_skill("dodge")) )
    {
        damage = me->query_skill("killingdragon-yet blade")+random(me->query("str")) +random(target->query("str"))+random(target->query("con"))-target->query_armor() - random(target->query_armor()/3);
        message_vision(HIR "\n�u�M�v"HIC"���@�n�A�u��$n�餺�@�}"HIY"����"HIC"�z�g ! ! !�C\n" NOR,me,target);

        damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
        target->receive_damage("hp",damage,me);
        if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
            tell_object(me,HIY"("+damage+")"NOR);
        if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
            tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
        message_vision("\n",target);
        COMBAT_D->report_status(target);
    }
    else {
        message_vision(HIG "\n$n�Ⲵ�b�� . . . �⦣�}�ê��k�L�@�T\n" NOR,me,target);
    }
    if(!me->is_fighting(target)) me->kill_ob(target);
}

void delay(object me)
{
    object weapon;
    if( !me ) return;

    weapon=me->query_temp( "weapon" );

    if( !weapon || weapon->query("skill_type") != "blade" )
    {
        me->map_skill("blade");
        me->reset_action();
        return;
    }

    if( me->query_skill_mapped("blade")!="killingdragon-yet blade" )
    {
        return;
    }

    if( me->query("ap")<1 )
    {
        me->map_skill("blade");
        me->reset_action();
        message_vision("\n"HIW"$N�����O���� . . . �L�k�ϥΡu�}�s��-�����v�C\n"NOR,me);
        return ;
    }

    if( me->is_fighting() ) me->receive_damage("ap",5);
me->skill_active( "killingdragon-yet blade",(: call_other, __FILE__, "delay", me :), 8);
}

int valid_learn(object me) {    return 1;       }
mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }



