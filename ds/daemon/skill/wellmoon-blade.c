/*
�����K�k �֫ӭx �i���M�k
1. ���� �ҿ׵L��䤣�ӡA��^���H�ݤ]�F�L��䤣��A��^���Ҥ���C�G�W����C
2. ���_ �ҿ׵��X�_�̡A�L�a�p�Ѧa�A���ܦp���e�A��������A�æ������O�]�C
3. �ο� �ΧL���k�A�H�Ѭ����A�O�H���Ѳ��}�A���Ѧa�Q�F���ѳӼġA���ѩT�v�C
4. �L�B �W�����@�ۡA���o�O�t�K�۵�h�ꤧ�A��h�ꤧ�A�L�����B���ۼơC
5. �ѫ� �X�M�p���l�A�ݼĤH�p������A�S���T�w�ۦ��C
6. �ԩw �D�������X���A�D���Ӥ���L�A�t�O�U�|�U��A�@�Ԧөw
7. �t�� ��e�p���A��}�p�L�A�I���p���A���ʦp�s�A�����p���A�ʦp�p�_�A�G�L�Q�ӡA���Q�[
8. ��� �謰���A�ꬰ��;������A������C�������H�A�ѤH�X�@�A�A���i��

Tmr 2007/05/02

*/
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

#define SKILL_NAME "wellmoon-blade"
        
void delay(object me);

mapping *action = ({
                       ([
                            "action": "$N�\\�X"HIR"�i"NOR"����"HIR"�j"NOR"�[�աA�L��䤣�ӡA��^���H�ݤ]�A�@�M�p�y�P�q�{���a��V$n"NOR"��$l",
                            "damage":                10,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "$N�M�k�X�_���p�L�a���Ѧa�A�@��"HIR"�i"NOR"���_"HIR"�j"NOR"��$n"NOR"��$l�A�h",
                            "damage":                15,
                            "attact_type":  "bar",
                            "damage_type":  "�A��",
                        ]),
                       ([
                            "action": "$N�H�Ѭ����A�ϥX"HIR"�i"NOR"�ο�"HIR"�j"NOR"�A$w"NOR"�q���i��ĳ�����ץX�M�A�S�Ʀ����A�w�O��V$n"NOR"��$l",
                            "damage":                10,
                            "attact_type":  "bar",
                            "damage_type":  "�A��",
                        ]),
                       ([
                            "action": "$N�������s��K�M�A�o�O�M�M��ۡA��ӳ��O"HIR"�i"NOR"�L�B"HIR"�j"NOR"�A�⤤$w"NOR"���ର��ۼA�V$n"NOR"��$l",
                            "damage":                15,
                            "attact_type":  "bar",
                            "damage_type":  "�A��",
                        ]),                   
                       ([
                            "action": "$N�X�M�p���l�A�b�ݲM$n"NOR"���X�ۤ���A�ϥX"HIR"�i"NOR"�ѫ�"HIR"�j"NOR"�A�⤤$w"NOR"���������A�V$n"NOR"��$l",
                            "damage":                10,
                            "attact_type":  "bar",
                            "damage_type":  "�A��",
                        ]),
                       ([
                            "action": "$N�D�������X���A�D���Ӥ���L�A�ϥX"HIR"�i"NOR"�ԩw"HIR"�j"NOR"�A�⤤$w"NOR"�@�Ԧөw�w�O��$n"NOR"��$l�A�h",
                            "damage":                15,
                            "attact_type":  "bar",
                            "damage_type":  "�A��",
                        ]),                   
                         ([
                            "action": "$N���ʦp�s�B�ʦp�p�_�A���O"HIR"�i"NOR"�t��"HIR"�j"NOR"�A�⤤$w�e�p���B�}�p�L"NOR"���a�婹$n"NOR"��$l�h",
                            "damage":                10,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "�u��$N�M�ۥH�謰���A�ꬰ���A�ϥX"HIR"�i"NOR"���"HIR"�j"NOR"�A�⤤$w"NOR"���p�������H�A�ѤH�X�@�A��$n"NOR"��$l�A�h",
                            "damage":                15,
                            "attact_type":  "bar",
                            "damage_type":  "�A��",
                        ]),                         
                       });


string *acts = ({
        "����", "���_", "�ο�", "�L�B", "�ѫ�", "�ԩw", "�t��", "���"
});

// �üƿ�@��
string random_act() {
        return acts[ random(8) ];
}

void improve_skill(object me) {
    me->improve_skill(SKILL_NAME, 1 + random(me->query_int()/2));
    me->improve_skill("blade",1 + random(me->query_int()/2));
}

/* �Z���l�� */
void damage_weapon(object me) {
    if( objectp(me->query_temp("weapon")) )
        me->query_temp("weapon")->attack(); // wp �l�a�v add by wilfred
}

/* �P�_�O�_�ݭn�ܶˮ`�Ʀr */
void show_damage(object me, object target,int damage) {
    if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
        tell_object(me,HIY"("+damage+")"NOR);
    if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
        tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
    if(wizardp(me) && me->query("env/debug"))
        tell_object(me,"  �y��"+damage+"�I�ˮ`!!\n");
}

/* �P�_�O�_�٥��޵o�԰� */
void check_combat(object me, object target) {
    if( !objectp(me) ) return;
    if( !objectp(target) ) return;
    if(!me->is_fighting(target)) me->kill_ob(target);
    if(!target->is_fighting(me)) target->kill_ob(me);
}

int get_tiger_damage(object me, object target)
{
     int damage;
    damage = me->query_skill(SKILL_NAME) + me->query_damage();
    damage = damage - target->query_armor()/2 - random(target->query_armor()/2);

    return COMBAT_D->Merits_damage(me, target, damage, "bar");
}

void clear(object me){
        if( !objectp(me) ) return;
        tell_object(me,"�A�i�H�A�ϥΡu������v�F�C\n");

        me->delete_temp("ARMY_WELL_MOON_BLADE");
}


/* ������ �S�� */
void do_tiger_attack(object me) {

    object weapon;
        object *targets;
    int damage, target_d, sk;
        int i, j, k, s, max;
    string msg;

     me->start_busy(1);
     me->receive_damage("ap", 50, me);
     me->set_temp("ARMY_WELL_MOON_BLADE",1);

    weapon=me->query_temp("weapon");
    message_vision(
                HIC "\n$N�ߤƦ��F���������A�L��Lê�A�u�O���[�a�ϬM�ۤj�t�z�������@���C\n"NOR, me);

    sk = me->query_skill(SKILL_NAME);
        max = 1;
        if(sk>=90) max += 1;
        if(sk>=70) max += 1;    // �̦h�T�ӤH

        targets = me->query_enemy();
        s = sizeof(targets);
        for(i=0, j=0; i < s && j < max;i++, j++) {
         if(!targets[i]) continue;
         if( !me->is_fighting(targets[i]) ) continue;
         if( environment(me) != environment(targets[i]) ) continue;
            target_d = -COMBAT_D->dodge_factor(targets[i],"dodge")*10/15;

                // �X�T�M
                for(k=0;k<3;k++) {
                    if( sk + random(sk/2) > random(target_d) ) {
                        damage = get_tiger_damage(me, targets[i]);
                        if( damage <= 0 ) {
                                message_vision(CYN "���O$N�M�۵L�O�A�L�k�o���������ĪG�C\n" NOR, me, targets[i]);
                        } else {
                                msg = HIR "$N�ϥX�����K�k��"HIY"�i" + random_act() +"�j"HIR"�A$n" HIR"�R�����ۡA��h�T�B�A�y�W���C�����A���ˤ����I�I" NOR;
                                message_vision(msg, me, targets[i]);
                                targets[i]->receive_damage("hp",damage,me);
                                damage_weapon(me);                      // �Z���l��
                                show_damage(me, targets[i], damage);        // ��ܶˮ`�Ʀr
                                message_vision("\n", me);
                                COMBAT_D->report_status(targets[i]);
                        }
                    } else {
                        message_vision(CYN "���O$N�M�ۿ𺢡A���L�F�������ɾ��C\n" NOR, me, targets[i]);
                    }
                }
        }
        improve_skill(me);


        if(!userp(me)) {
                // for master
                call_out("clear", 4, me);
                return;
        }

        if(me->query_bio() < 6 )
                call_out("clear", 20-me->query_bio(), me);
        else
                call_out("clear", 8, me);
}


int exert(object me, object target, string arg)
{
        int sk;
    object weapon;
    sk = me->query_skill(SKILL_NAME);
    weapon=me->query_temp("weapon");
    if( me->is_ghost() ) return notify_fail("�A�w�g���F�A�Ч��I�h�_���a�C\n");
    if (!weapon) return notify_fail("�A�⤤�������M�~��I�i�u�����K�k�v�C\n");
    if(weapon->query("skill_type")!="blade") return notify_fail("�A�⤤�������M�~��I�i�u�����K�k�v�C\n");

    if(arg=="off" )
    {
        if( me->query_skill_mapped("blade") != SKILL_NAME)
            return notify_fail("�A�èS���ϥΡu�����K�k�v�C\n");
        me->map_skill("blade");
        me->reset_action();
        write("�ޯ�u�����K�k�v�w�����C\n");
        return 1;
    }

    if(me->query("ap")<10 || me->query("hp")<10) return notify_fail("�A�����骬�p�L�k�ϥΡu�����K�k�v�C\n");

    //�ĤG��exert
    if(me->query_skill_mapped("blade")==SKILL_NAME)
    {
        if( !target ) target = offensive_target(me);
        if (!me->is_fighting())
            return notify_fail("�A�w���b�I�i�u�����K�k�v�F�C\n");
        if (me->query_skill(SKILL_NAME) < 50)
            return notify_fail("�A�ثe�ٵL�k�ϥX�u������v���ۡC\n");
        if(me->query("ap") < 100)
            return notify_fail("�A�ثe�����l�����A�L�k�ϥX�u������v���ۡC\n");
            if(me->query_temp("ARMY_WELL_MOON_BLADE") )
            return notify_fail("�A�u�ɶ����L�k�A�ϥΡu������v�C\n");

        //�����ʪ��n�S�O�`�N�n�[�U�����.
        if(!me->can_fight(target)) return me->can_fight(target);
        if(!me->is_fighting(target) ) return notify_fail("�A�èS���M���b�԰����C\n");

        do_tiger_attack( me ); // �S�� ������

        return 1;
    }

        if(!me->skill_active( SKILL_NAME,(: call_other, __FILE__, "delay", me ,5:), 10)) return notify_fail("�A�����K�k���ʧ@�٨S�����C\n");
    me->map_skill("blade", SKILL_NAME);
    me->reset_action();
    message_vision("$N�I�i�_�u�����K�k�v�A�M�ۦ��p�������H�A�ѤH�X�@�A�A���i���C\n"NOR,me);
    me->receive_damage("ap",10);
    me->start_busy(2);
    return 1;
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

    if( me->query_skill_mapped("blade")!=SKILL_NAME )
    {
        return;
    }
    if( me->query("ap")<10 )
    {
        me->map_skill("blade");
        me->reset_action();
        message_vision("\n"HIW"$N"HIW"����O�����L�k�~��I�i�����K�k�C\n"NOR,me);
        return ;
    }

    if( me->is_fighting() ) me->receive_damage("ap",5);
        me->skill_active( SKILL_NAME,(: call_other, __FILE__, "delay", me :), 8);
}

int valid_learn(object me) {    return 1;       }

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }

int improve_limite(object ob)
{
     return 60 + ob->query_str();

}

