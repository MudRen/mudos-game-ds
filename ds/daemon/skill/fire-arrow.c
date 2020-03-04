#include <ansi.h>
inherit SSERVER;
inherit SKILL;

int cast(object me, object target)
{
    int sk = me->query_spell("fire_arrow");
    int cost = sk*10 /9;

    if ( !target ) target = offensive_target(me);
    if ( !target ) return notify_fail("�A�n��֬I�i�o�Ӫk�N�S\n");
    if( (int)me->query("mp") <  cost )
        return notify_fail("�A���믫�O�����F�C\n");
    if( !living(target) ) return notify_fail("�L���ন���ؼСC\n");
    if( !target->can_fight(me) ) return target->can_fight(me);
    me->add("sp", -cost);
    message_vision(
        HIY"$N"HIY"��M���өԺ������ʧ@�A�åB��D�G�u�]�O���W�������I�нᤩ�^���K���O�A���K���b�I�v\n"NOR
        HIR"        �]�O���_��$N"HIR"���⤧���E���A�@�����⪺���K���b�a�B�b$N"HIR"���e�I\n"NOR
        , me);
    me->start_busy(1);
    call_out("start", 0, me, target);
    return 1;
}

int start( object me, object target ) //�}�l�������禡�W�٥����Τ@
{
    int damage, sk;
    object env;
    //�bdelay����,�n�Ҽ{�����ܤ�
    if(!me) return 0;
    env = environment(me);
    //1.me �i�঺�`�άO���u
    if(!target || env != environment(target)) {
        message_vision(HIG"$N"HIG"���}��M���������F�C\n"NOR, me);    //2.target�i�঺�`�άO���u
        return 1;
    }                                                           //3.�ؼХi��|���}
    if( random(100) > me->query_wil() ) {
        message_vision(HIY"$N"HIY"���k�N���ѤF�C\n"NOR, me);
        return 1;
    }
    sk = me->query_spell("fire_arrow");
    damage = me->query_might()/2 + (sk*50);
    damage /= 2;
    damage += random(damage);
    damage = target->receive_magic_damage("hp", damage, me, "fire");
    message_vision(
        HIY"\n$N��X�⤤���A���W���K���b�H���g�X�C\n"NOR
        HIY"$n"HIY"�Q�b�g���A�y�� "+damage+" �I"HIR"���K�ˮ`�C\n"NOR
        , me, target);
    target->kill_ob(me);      //�����ʪk�N�[�W�o�@��
    COMBAT_D->report_status(target);       //�[�W�o��i�H���target�����d���p
    return 1;
}

string name()
{
    return "���K�b";
}

mixed query_spell_data(string arg)
{
    if( !arg ) return 0;
    switch (arg) {
    case "limit_level": return 10;
    case "spell_attr": return "fire";
    default: return 0;
    }
}


