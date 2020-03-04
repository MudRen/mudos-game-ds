// ���ͳZ (longevity-force)
// Tmr 2007/07/19

#include <ansi.h>
#define SKILL_NAME "longevity-force"

inherit SKILL;
inherit SSERVER;

int do_heal(object me) {
    int force,sk,heal;

    force = me->query_skill("force", 2);
    sk = me->query_skill(SKILL_NAME, 2);
    heal = force + sk;
    if (me->is_fighting() ) return notify_fail("�A�����۾԰��A�S��������");
    if(me->query("hp") >= me->query("max_hp") ) return notify_fail("�A�����d���p�w�F�A�p�C\n");
    if(me->query("ap") < heal/3 ) return notify_fail("�A�����l�����A�L�k�ϥ����˥\\��C\n");

     message_vision( "$N�ϥX���ͳZ"HIW"���˯u��"NOR"�A���ͯu���_���Э��𩲡A�����˶ն}�l�n��F�C\n" ,me);
    me->receive_damage("ap", heal/2);
    me->receive_heal("hp", heal);
    me->start_busy(1);
    me->improve_skill(SKILL_NAME, 1 + random(me->query_con()/4) );
    me->improve_skill("force", 1 + random(me->query_con()/4)  );
    return 1;
}

int do_spiral(object me, object target) {
    int force,sk;
      int damage;
    force = me->query_skill("force", 2);
    sk = me->query_skill(SKILL_NAME, 2);

    if(!target) target = offensive_target(me);  // �ĤH
    if( !target )
        return notify_fail("�A�n��֨ϥΡH\n");
    if(me->query_skill( SKILL_NAME ) < 30)
        return notify_fail("�A��"+SKILL_NAME+"���ݹF��30�šA�~��o�X�����l�C\n");
    if(me->query("ap") < 100)
        return notify_fail("�A�����l�����o�X���ۮ�l�C\n");
    if(!me->is_fighting(target) )
        return notify_fail("�A�èS���P���b�԰��C\n");

    message_vision( HIW "\n$N�B�_���ͳZ"HIC"���۫l"HIW"�A�u��߮ɦp���t�j�۪��L�Φy�աA�q���i��ĳ����V��$n"HIW"��h�I�I\n" ,me , target);
    me->start_busy(1);
    me->receive_damage("ap", 40 );

    if( random(sk*2) > COMBAT_D->attack_factor(me, SKILL_NAME)*10/15
            || random(sk*2) > -COMBAT_D->dodge_factor(target,"dodge") ) {
        // �R��
        damage = 1 + random(sk);
        message_vision( HIR "�²r�L�۪����۫l�D�I�J$n"HIR"�n�ޡA$n"HIR"�u��B��n�ɤ��Z�A�@�f�𴣤��W�ӡI�I("+damage+")\n\n" NOR, me , target);
        target->start_busy(2);
         target->receive_damage( "hp", damage, me );
            me->improve_skill(SKILL_NAME, 1 + random(me->query_con()/4) );
            me->improve_skill("force", 1 + random(me->query_con()/4)  );
    } else {
           message_vision( CYN "���O�Q$n"CYN"����L�I�a�פF�}�h�C\n" NOR,me , target);
    }

    return 1;
}

int exert(object me,object target, string arg)
{
    //���˥\��
    if( arg =="heal" )
        return do_heal(me);

    return do_spiral(me, target);
//    return notify_fail("���ͳZ���\\�঳�G����(heal) �� ���۫l(exert longevity-force on [id])�C\n");
}

int valid_learn(object me)
{
    return 1;
}

int practice_skill(object me)
{
    return 1;
}


