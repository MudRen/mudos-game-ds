#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me);
void superpower(object me,object target,int z,int damage);
mapping *action = ({
        ([
        "action": "$N�@�ۡu"+HIW+"�R������"+NOR+"�v, $w�S�p���������V$n",
        "damage":                9,
        "dodge" :               10,
        "parry" :               10,
        "attact_type":  "bar",
        "damage_type":  "����",
        ]),
        ([
        "action": "$N���ϡu"+HIW+"�i������"+NOR+"�v, �⤤$w�R�X�@���M��, �A�V$n",
        "damage":                12,
        "dodge":                 -10,
        "parry" :                -6,
        "attact_type":  "bar",
        "damage_type":  "�h�B�A��",
        ]),

        ([
        "action": "$N����u"+HIW+"����g��"+NOR+"�v�A$w���a�p�^���ձ٦V$n",
        "damage":                13,
        "dodge" :                -5,
        "parry" :               -10,
        "attact_type":  "bar",
        "damage_type":  "�ٶ�",
        ]),

        ([
        "action": "$N�M���@�n�u"+HIW+"�x���e�y"+NOR+"�v, �������$n����, �@�M��V$n���",
        "damage":                9,
        "dodge" :                10,
        "parry" :               15,
        "attact_type":  "bar",
        "damage_type":  "���",
        ]),

        ([
        "action": "$N�C��~�{�u"+HIW+"�t�����"+NOR+"�v, ���Ф@�ޤ@�a, �k��$w���ձ��V$n",
        "damage":                10,
        "dodge" :               -20,
        "parry" :                30,
        "attact_type":  "bar",
        "damage_type":  "����",
        ]),

        ([
        "action": "$N�y��@�I�u"+HIW+"�ܮ�����"+NOR+"�v�A$w�@���d�����$n�e��ӥh",
        "damage":                10,
        "dodge" :               -10,
        "parry" :                15,
        "attact_type":  "bar",
        "damage_type":  "���",
        ]),

        ([
        "action": "$N�����ƶh,�u"+HIW+"�Ѯ��s��"+NOR+"�v�A���榳�p���s�@���D�_, $w�����A�V$n",
        "damage":                11,
        "dodge" :                20,
        "parry" :               -10,
        "attact_type":  "bar",
        "damage_type":  "�A��",
        ]),

        ([
        "action": "$N�ϥX�u"+HIW+"�W���Læ"+NOR+"�v�⤤$w�r���A�ۦ��j�}�j��, �h�ѤM���V$n",
        "damage":                14,
        "dodge" :                10,
        "parry" :                15,
        "attact_type":  "bar",
        "damage_type":  "�h�B���",
        ]),
        ([
        "action": "$N�y��@�W�u"+HIW+"�����~��"+NOR+"�v�A$w���ǥX�d�E���n, �p���F�ʯ�ĦV$n",
        "damage":                14,
        "dodge" :               -15,
        "parry" :                11,
        "attact_type":  "bar",
        "damage_type":  "����",
        ]),
        ([
        "action": "$N���P�ɵM�u"+HIW+"�����h�y"+NOR+"�v�A�⤤$w�禳���h����, �w�w���V$n��$l",
        "damage":                10,
        "dodge" :                10,
        "parry" :                10,
        "attact_type":  "bar",
        "damage_type":  "���",
        ]),
        ([
        "action": "$N�j�ܤ@�n�u"+HIW+"�ɮ����"+NOR+"�v�A$w�e���V$w��$l���U�B�j�ޡA�զp�}��",
        "damage":                13,
        "dodge" :                20,
        "parry" :                30,
        "attact_type":  "bar",
        "damage_type":  "�ζ�",
        ]),
        ([
        "action": "$N�y��Y�W�u"+HIW+"�߮�����"+NOR+"�v��I�s�e�A$w�P�ɽw�w�٦V$w, ",
        "damage":                13,
        "dodge" :               -25,
        "parry" :               -25,
        "attact_type":  "bar",
        "damage_type":  "�ٶ�",
        ]),
});
int exert(object me, object target, string arg)
{
        int sk,damage;
        object weapon;
        mapping type;
        sk=me->query_skill("sea-blade");
        weapon=me->query_temp("weapon");
        if( me->is_ghost() ) return notify_fail("�����H...?\n");
        if (!weapon) return notify_fail("�A�n��@��M�~��I�i�u�ɮ��M�Z�v�C\n");
        if(weapon->query("skill_type")!="blade") return notify_fail("�A�⤤�������M�~��I�i�u�ɮ��M�Z�v�C\n");
        if(arg=="off" )
        {
                if( me->query_skill_mapped("blade")!="sea-blade")
                        return notify_fail("�A�S���B��u�ɮ��M�Z�v�C\n");
                me->map_skill("blade");
                me->reset_action();
                write("�u�ɮ��M�Z�v�w�����C\n");
                return 1;
        }

        if(me->query_skill("sea-blade")<2) return notify_fail("�̧A�ثe���y�ڡA�|�L�k�B��u�ɮ��M�Z�v�C\n");
        if(me->query("ap")<20 || me->query("hp")<20) return notify_fail("�A�����骬�p�L�k�B��u�ɮ��M�Z�v�C\n");


        //�ĤG��exert
        if(me->query_skill_mapped("blade")=="sea-blade")
        {
        if( me->is_ghost() ) return notify_fail("�����H...?\n");
                if( !target ) target = offensive_target(me);
                if (!me->is_fighting()) 
                return notify_fail("�A�w�b�B��u�ɮ��M�Z�v�F�C\n");
                if (me->query_skill("sea-blade") < 60)
                return notify_fail("�̧A�ثe�u�ɮ��M�Z�v���y�ڡA�L�k�ϥΡu���Ǥd�t�v�C\n");
              if(me->query("ap")<50) 
                return notify_fail("�A�ثe�����l�����A�L�k�ϥΡu���Ǥd�t�v�C\n");
              if(!me->can_fight(target)) return me->can_fight(target);
        if(!me->is_fighting(target) ) return notify_fail("�A�S���b�԰���....\n");
                message_vision(HIW"$N���l�@���A��ɤ��СA�ǳƹB�_�u���Ǥd�t�v�C\n\n"NOR,me);
                me->receive_damage("ap",15+random(32));
                me->start_busy(1+random(2));
                call_out("superpower",1,me,target,1,damage);
                return 1;
        }
        
        if(!me->skill_active( "sea-blade",(: call_other, __FILE__, "delay", me ,5:), 10)) return notify_fail("�A�u�ɮ��M�Z�v���ʧ@�٨S�����C\n");
        me->map_skill("blade", "sea-blade");
        me->reset_action();
        message_vision("\n"HIW"$N���_�⤤"+weapon->query("name")+HIW "�A�}�l�B��u�ɮ��M�Z�v�C\n"NOR,me);
        me->receive_damage("ap",15);
        me->start_busy(3);
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

       z=me->query_skill("sea-blade");
       msg = "�uť$N�j�ܤ@�n�A�⤤���M�l�ǤF$N�����l�A�}�l�B��"HIW"�u���Ǥd�t�v"NOR"�A\n";
       msg +=HIW"$N�N�ĤH���l�@�ޤ@�a, �ɦ���$w����, �Ͼ_���դw�դ��i��,\n"NOR;
       msg +=HIW"$N�A�ܤ@�n, �u���Ǥd�t�v, �⤤���M�ɱN$N����դϼu�Ӧ^!!\n"NOR;
       message_vision(msg, me, target);

       if( z/2 > random(target->query_skill("dodge")) )
       {
       damage = me->query_skill("sea-blade")+random(me->query("str")) +random(target->query("str"))-target->query_armor()/2 - random(target->query_armor()/3);
       message_vision(HIR "\n���G$N��պɼƳQ�ϼu, $N�y�ɦp�_�u������, �I�ǩ��h!!�C\n" NOR,me,target);

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
            message_vision(HIW "\n$n�j�奢��A�榬���, �I�I�k�L�@�T....\n" NOR,me,target);
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

        if( me->query_skill_mapped("blade")!="sea-blade" )
        {
                return;
        }

        if( me->query("ap")<20 )
        {
                me->map_skill("blade");
                me->reset_action();
                message_vision("\n"HIW"$N"HIR"����O�����~��B��u�ɮ��M�Z�v�C\n"NOR,me);
                return ;
        }

        if( me->is_fighting() ) me->receive_damage("ap",5);
        me->skill_active( "sea-blade",(: call_other, __FILE__, "delay", me :), 8);
}

int valid_learn(object me) {    return 1;       }
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }
