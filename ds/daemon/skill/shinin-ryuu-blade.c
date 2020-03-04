//�s���y�M�N(Shinin-ryuu-blade)

//by DS-KSJ

#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me);
void superpower(object me,object target,int z,int damage);
mapping *action = ({
                       ([
                            "action": "$N�\\�X�i�����j�[�աA�N$w���M�y���V$n�������A�b$n����L�ʪ��������t�٦V$n��$l",
                            "damage":                10,
                            "dodge" :               -10,
                            "parry" :               -10,
                            "attact_type":  "bar",
                            "damage_type":  "�M��",
                        ]),
                       ([
                            "action": "$N�w�w�N$w�u���餤�u�W�|���Y�W�A�\\�X�i�W�q�j���աA�P�ɫ�ܤ@�n�j�P��ժ��A$n��$l",
                            "damage":                12,
                            "dodge":                 10,
                            "parry" :                10,
                            "attact_type":  "bar",
                            "damage_type":  "�A��",
                        ]),

                       ([
                            "action": "$N���毸���\\�X�i���q�j�[�աA�k�}�e��@�����Z�A���}�}��۵M�W���A$w���M�y���V$n���|��
                            �A���ΰ��M���e�@�ʡA���Y$w�w��V$n��$l",
                            "damage":                8,
                            "dodge" :                -5,
                            "parry" :               -10,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N�N$w�M�y�U�����V��⽥�U�A���O�i�U�q�j���[�աA�Ⲵ�N�R�a�[��$n���ۦ��A�M��@��
                            �j���٦V$n��$l",
                            "damage":                9,
                            "dodge" :                10,
                            "parry" :               -15,
                            "attact_type":  "bar",
                            "damage_type":  "�ٶ�",
                        ]),

                       ([
                            "action": "$N�ѥ��W�q���[�է��ܬ��i�K�ۡj�[�աA�⤤$w������K�Ӥ��A$N�N�R�P�_$n���ʧ@��A
                            ���t����$n��$l����C",
                            "damage":                12,
                            "dodge" :                20,
                            "parry" :               -30,
                            "attact_type":  "bar",
                            "damage_type":  "�ٶ�",
                        ]),

                       ([
                            "action": "$N�Ѥ��q�[�հh�k���A�N�M�m��k��y���A�M�y�b��A�Φ��i��y�j�[�աA$n�L�k�P�_$N��
                            �����Z�����h�������ڡA$w�w��٦V$n��$l�C",
                            "damage":                11,
                            "dodge" :               -10,
                            "parry" :                 5,
                            "attact_type":  "bar",
                            "damage_type":  "�ٶ�",
                        ]),
                   });

int exert(object me, object target, string arg)
{
    int sk,damage;
    object weapon;
    sk=me->query_skill("shinin-ryuu-blade");
    weapon=me->query_temp("weapon");
    if( me->is_ghost() ) return notify_fail("�����F�A�٭n�X�Ӯ`�H�H\n");
    if (!weapon) return notify_fail("�A�⤤�������M�~��I�i�u�s���y�M�N�v�C\n");
    if(weapon->query("skill_type")!="blade") return notify_fail("�A�⤤�������M�~��I�i�u�s���y�M�N�v�C\n");

    if(arg=="off" )
    {
        if( me->query_skill_mapped("blade")!="shinin-ryuu-blade")
            return notify_fail("�A�èS���ϥΡu�s���y�M�N�v�C\n");
        me->map_skill("blade");
        me->reset_action();
        write("�ޯ�u�s���y�M�N�v�w�����C\n");
        return 1;
    }

    //  if(me->query_skill("shinin-ryuu-blade")<10) return notify_fail("�̧A�ثe���\\�O�A�|�����I�i�u�s���y�M�N�v�C\n");
    if(me->query("ap")<10 || me->query("hp")<10) return notify_fail("�A�����骬�p�L�k�ϥΡu�s���y�M�N�v�C\n");

    //�ĤG��exert
    if(me->query_skill_mapped("blade")=="shinin-ryuu-blade")
    {
        if( me->is_ghost() ) return notify_fail("�����F�A�٭n�X�Ӯ`�H�H\n");
        if( !target ) target = offensive_target(me);
        if (!me->is_fighting())
            return notify_fail("�A�w���b�I�i�u�s���y�M�N�v�F�C\n");
        if (me->query_skill("shinin-ryuu-blade") < 50)
            return notify_fail("�̧A�ثe�s���y�M�N���y�ڡA�L�k�ϥε��ۡC\n");
        if(me->query("ap")<50)
            return notify_fail("�A�ثe�����l�����A�L�k�ϥε��ۡC\n");

        //�����ʪ��n�S�O�`�N�n�[�U�����.
        if(!me->can_fight(target)) return me->can_fight(target);
        if(!me->is_fighting(target) ) return notify_fail("�A�èS���M���b�԰����C\n");
        message_vision(HIW"$N�N�⤤"+weapon->query("name")+HIW "���V����ǳƨϥX���ޡ�"HIC"�i�ܩF����M�j�C\n\n"NOR,me);
        me->receive_damage("ap",15+random(16));
        me->start_busy(1+random(2));
        call_out("superpower",1,me,target,1,damage);
        return 1;
    }

if(!me->skill_active( "shinin-ryuu-blade",(: call_other, __FILE__, "delay", me ,5:), 10)) return notify_fail("�A�s���y�M�N���ʧ@�٨S�����C\n");
    me->map_skill("blade", "shinin-ryuu-blade");
    me->reset_action();
    message_vision("\n"HIW"$N���ʤ⤤"+weapon->query("name")+HIW "�\\�X�u�s���y�M�N�v���򥻬[�աC\n"NOR,me);
    me->receive_damage("ap",10);
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

    z=me->query_skill("shinin-ryuu-blade");

    msg = HIW"$N�G�����t�ĦV$n���e�P�ɩ��W�D�_�A"HIC"�i�ܩF����M�j"HIW"�ۦ��ѤU���W�����ٶ�$n�C\n"NOR;
    message_vision(msg, me, target);

    if( z/3 + random(z) > random(target->query_skill("dodge")) )
    {
        damage = me->query_skill("blade") + random(me->query("str")) - target->query_armor()/2 - random(target->query_armor()/2) - (target->query("con"));
        if(damage>225) damage=225+((damage-225)/5);
        if(damage<20) damage=15+random(8);

        message_vision(HIR "\n���G$n���ݤf���쭫�СA�A���q�o���a�A��M���ˤ����C\n" NOR,me,target);

        // �W�[�����ˮ`���v�T
        damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
        target->receive_damage("hp",damage,me);
        if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
            tell_object(me,HIY"("+damage+")"NOR);
        if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
            tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
        message_vision("\n",target);
        COMBAT_D->report_status(target);
    }
    else
    {
        message_vision(HIW "\n$n�s�s��h�A�I�I�׶}�F���r����աC\n" NOR,me,target);
    }
    if(!me->is_fighting(target)) me->kill_ob(target);        //�����ʧޯ�[�W�o�� Luky add.
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

    if( me->query_skill_mapped("blade")!="shinin-ryuu-blade" )
    {
        return;
    }
    if( me->query("ap")<10 )
    {
        me->map_skill("blade");
        me->reset_action();
        message_vision("\n"HIW"$N"HIW"����O�����L�k�~��I�i�s���y�M�N�C\n"NOR,me);
        return ;
    }

    if( me->is_fighting() ) me->receive_damage("ap",5);
me->skill_active( "shinin-ryuu-blade",(: call_other, __FILE__, "delay", me :), 8);
}

int valid_learn(object me) {    return 1;       }

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }
