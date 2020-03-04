// �����v  �j�k - �R��j�k (ablaze-pike)
// Tmr 2007/10/11

#include <ansi.h>
inherit SKILL;
inherit SSERVER;

#define SKILL_NAME "ablaze-pike"
        
void delay(object me);

mapping *action = ({
                       ([
                            "action": "$N�⤤$w�j�Y�a�_�ƭӫ�ۡA�ϥX�_�⦡"+HIR"�y"+NOR"���P�E�{"+HIR"�z"+NOR"�A��l�p�ɲɤ��P�K�h�A����$n$l",
                            "damage":                25,
                            "attact_type":  "sou",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N�⤤$w�j�դj���A�ϥX"+HIR"�y"+NOR"���y���W"+HIR"�z"+NOR"�A�j�y�������ʨ�V$n$l",
                            "damage":                20,
                            "attact_type":  "sou",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N�ϥX����"+HIR"�y�­�ѤU�z"+NOR"�A$w�Ƨ@�d�ʹD�j�v�A�����w�N$n���h�����I�_�F�����A�s���w�]����q�L",
                            "damage":                45,
                            "attact_type":  "sou",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N�樬�W�a�ϥX"+HIR"�y"+NOR"�����]��"+HIR"�z"+NOR"�A�t�@�}�}�I�o�[�b�W�ߦa�W���}���L����A$w�H�_�����i���y�񱽦V$n$l�n�`",
                            "damage":                30,
                            "attact_type":  "sou",
                            "damage_type":  "�A��",
                        ]),

                       ([
                            "action": "$N�E�_�R��u�l�E�X����"+HIR"�y"+NOR"���D�g�R"+HIR"�z"NOR+"�A$w�@�j�ư��d�U���D�A����$n$l�n�`",
                            "damage":                 25,
                            "attact_type":  "sou",
                            "damage_type":  "���",
                        ]),
                   });

void improve_skill(object me) {
    me->improve_skill(SKILL_NAME, 1 + random(me->query_int()/2));
    me->improve_skill("fork",1 + random(me->query_int()/2));
}

/* �Z���l�� */
void damage_weapon(object me) {
    if( objectp(me->query_temp("weapon")) )
        me->query_temp("weapon")->attack(); // wp �l�a�v add by wilfred
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
    int damage, power;
    // �H�]�ʪ��ƭȬ���¦
    power = CLASS_D("ancestor")->getMagicLevel(me, target);
    damage = me->query_skill(SKILL_NAME) + me->query_damage();
    damage = damage + power*70;
    damage = damage - target->query_armor()/2 - random(target->query_armor()/3);

    return COMBAT_D->Merits_damage(me, target, damage, "sou");
}

void clear(object me){
        if( !objectp(me) ) return;
        tell_object(me,"�A�ϥΡu�L�j�աv���l�`�w�g��_�F�C\n");
        me->delete_temp("ABLAZE_PIKE_ACT");
}


/* �L�j�� �S�� */
void do_tiger_attack(object me, object target) {

    object weapon;
    int damage, target_d,sk;
    int power;
    string msg;

    me->start_busy(2);
    me->receive_damage("ap", 50, me);
    me->set_temp("ABLAZE_PIKE_ACT",1);

    weapon=me->query_temp("weapon");
    msg = HIM"\n$N"HIM"�V�G���j�^������A�N�N�ݵۼĤH�A�S���H����$N"HIM"���j�|�Ѩ��Ө��ץX��A\n"
                        "�o�O�R��j�k�W�_�ѤU��"HIR"�y�L�j�աz"HIM"�A�Ѧ��j�ܵL�j�A�ФH����������i�Ȫ��V�G���j�U�@�B���ܤơC\n"
                        "�V�G���j�@�I�@��A�d���I�j�~�A����{���A�N$n���o�L�k����A�s�s�ѩۡI�I\n"NOR;

    damage = get_tiger_damage(me, target);
    if( damage <= 0 ) {
        msg += HIW "�i���Q$n" HIW "���}�P�R���@���F�C\n" NOR;
        message_vision(msg, me, target);
        check_combat(me, target);
        return;
    }

    target_d = -COMBAT_D->dodge_factor(target,"dodge")*10/15;
    sk = me->query_skill(SKILL_NAME);
    if( sk + random(sk/2) > random(target_d) ) {
        target->receive_damage("hp",damage,me);
        target->start_busy(1);

        power = CLASS_D("ancestor")->getMagic(me, target);
        if( power > 0) {
                // ���]�ʥ[�v
                msg += HIR "$n"HIR"���Y�q��A"+HBK "�{�䪺�¦��z���X��" + HIR"�A���ˬ۷��Y��("+damage+")�I\n" NOR;
                 CLASS_D("ancestor")->deleteMagic(me, target);
        } else {
                msg += HIR "$n"HIR"���Y�q��A�y��a�����ݡA�i�����˵۹ꤣ��("+damage+")�I\n" NOR;
        }
        message_vision(msg, me, target);
        damage_weapon(me);                      // �Z���l��
        COMBAT_D->report_status(target);
        improve_skill(me);
    } else {
        msg += HIW"�i�O�Q$n" HIW "���F�}�h�C\n" NOR;
        message_vision(msg, me, target);
    }

     call_out("clear", 8, me);
}


int exert(object me, object target, string arg)
{
    int sk;
    object weapon;
    sk = me->query_skill(SKILL_NAME);
    weapon=me->query_temp("weapon");
    if( me->is_ghost() ) return notify_fail("�A�w�g���F�A�Ч��I�h�_���a�C\n");
    if (!weapon) return notify_fail("�A�n���j�~��I�i�u�R��j�k�v�C\n");
     if(weapon->query("skill_type")!="fork") return notify_fail("�A�⤤�������j�~��I�i�u�R��j�k�v�C\n");

    if(arg=="off" )
    {
        if( me->query_skill_mapped("fork") != SKILL_NAME)
            return notify_fail("�A�èS���ϥΡu�R��j�k�v�C\n");
        me->map_skill("fork");
        me->reset_action();
        write("�ޯ�u�R��j�k�v�w�����C\n");
        return 1;
    }

    if(me->query("ap")<10 || me->query("hp")<10) 
                return notify_fail("�A�����骬�p�L�k�ϥΡu�R��j�k�v�C\n");

    //�ĤG��exert
    if(me->query_skill_mapped("fork")==SKILL_NAME)
    {
        if( !target ) target = offensive_target(me);
        if (!me->is_fighting())
            return notify_fail("�A�w���b�I�i�u�R��j�k�v�F�C\n");
        if (me->query_skill(SKILL_NAME) < 50)
            return notify_fail("�A�ثe�ٵL�k�ϥX�u�L�j�աv�����ۡC\n");
        if(me->query("ap") < 100)
            return notify_fail("�A�ثe�����l�����A�L�k�ϥX�u�L�j�աv�����ۡC\n");
        if(me->query_temp("ABLAZE_PIKE_ACT") )
            return notify_fail("�A�u�ɶ����L�k�A�ϥΡu�L�j�աv�C\n");

        //�����ʪ��n�S�O�`�N�n�[�U�����.
        if(!me->can_fight(target)) return me->can_fight(target);
        if(!me->is_fighting(target) ) return notify_fail("�A�èS���M���b�԰����C\n");

        do_tiger_attack(me, target); // �S�� �L�j��

        return 1;
    }

        if(!me->skill_active( SKILL_NAME,(: call_other, __FILE__, "delay", me ,5:), 10)) 
                return notify_fail("�u�R��j�k�v���ʧ@�٨S�����C\n");
    me->map_skill("fork", SKILL_NAME);
    me->reset_action();
    message_vision("$N���_�R��u�l�A�j�k�@�ܡA�}�l�I�i�_�u�R��j�k�v�C\n"NOR,me);
    me->receive_damage("ap",10);
    me->start_busy(2);
    //      me->start_call_out( (: call_other, __FILE__, "delay", me ,5:), 10);
    return 1;
}

void delay(object me)
{
    object weapon;
    if( !me ) return;

    weapon=me->query_temp( "weapon" );

    if( !weapon || weapon->query("skill_type") != "fork" )
    {
        me->map_skill("fork");
        me->reset_action();
        return;
    }

    if( me->query_skill_mapped("fork")!=SKILL_NAME )
    {
        return;
    }
    if( me->query("ap")<10 )
    {
        me->map_skill("fork");
        me->reset_action();
        message_vision("\n"HIW"$N"HIW"����O�����L�k�~��I�i�u�R��j�k�v�C\n"NOR,me);
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
     return 60 + ob->query_int();

}


