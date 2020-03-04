//�w�g  recite-sutra
//update 2000.6.2 by -Acme-
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me,int cost,int times);

int cast(object me, object target, string arg)
{
    int rs_sk,inn,tt,addexp;
    inn=me->query_int();
    rs_sk=me->query_spell("recite-sutra");

    tt= rs_sk / 10;
    if(tt < 1) tt=1;
    if(tt > 6) tt=6;

    if(me->is_fighting() )
    {
        if(rs_sk < 30)
            return notify_fail("�A�|�L�k���g�i�����l�p �j�C\n");

        //        if(me->query("ap") < (tt*15) )
        //                return notify_fail("�̧A�ثe�����A�A�L�k���g�i�����l�p �j�C\n");

        if(me->query("mp") < (tt*10) )
            return notify_fail("�̧A�ثe�����A�A�L�k���g�i�����l�p �j�C\n");

        if ( !target ) target = offensive_target(me);
        if(!target) return notify_fail("�A�n��֤��g�i�����l�p �j�H�H\n");
        if(!me->can_fight(target)) return me->can_fight(target);
        if(!me->is_fighting(target) )
            return notify_fail("�A�èS���M���b�԰����C\n");

        message_vision(HIB "\n$N"+ HIB "�~�a�h�F�ƨB�A����X�Q�@�ۦa���F�q�g��C\n" NOR,me);

        //      me->receive_damage("ap",tt*15);
        me->receive_damage("mp",tt*10 );

        if( random(150) > random(100) )
        {
            message_vision(HIC "\n���M�Ѫ���_�@�}�T�p�A�@�D�{�q�������ʦa���b$n"+ HIC"���W�I�I\n" NOR ,me,target);
            if(userp(target))       tell_object(target,HIR "�Aı�o�����@�}�o�¡C\n" NOR );
            target->receive_damage("hp",tt*10, me);
            target->apply_condition("five-thunder", tt );
            target->start_busy(1);
            target->set_temp("five-thunder-caster", me);
        }
        else message_vision(HIY "���G����Ƥ]�S���o��....\n" NOR ,me);
        me->improve_spell("recite-sutra",1 + random(1+me->query_int()/2 +me->query("level")/2));
        me->start_busy(1);
        return 1;
    }

    if(me->query("ap")<20 || me->query("mp")<20 )
        return notify_fail("�A�{�b�����A���ΡA����A���g�F�C\n");
    if(me->query_temp("is_busy/recite-sutra") )
        return notify_fail("�A�٦��t�@�i�L�A�ө��g�H�H\n");
    if( sizeof(me->query_temp("is_busy")) )
        return notify_fail("�A�{�b���b���C\n");

    if(!target) return notify_fail("�o�̨S���o�ӪF��C\n");

    if( userp(target) ) return notify_fail("�L�O���a�A�A�L�k�缾�a�W�͡C\n");

    //�]����id�P�_�O�_��skeleton,�ҥH�[�W�o��,����aid��skeleton

    if( !target->is_corpse() && target->query("id") != "skeleton" )
        return notify_fail("�A�u�������g�W�͡C\n");

    // �]�� is_corpse() ����P�_ ���\���e��(Skeleton) �u�n��id�P�_

    if( target->query("recite-sutra") )
        return notify_fail("�����F��w�F��跥�֥@�ɡC\n");
    if( me->query("evil") > 500 )
        return notify_fail("�A�L�󨸴c�A���L�k�R�U�ߨӬ��`��W��C\n");

    target->set("recite-sutra",1);
    message_vision(MAG "$N�ŤF�n�򸹡A�}�l���w�_�g��A�W��w���`��$n�C\n"NOR,me,target);

    me->start_busy(2);
    me->receive_damage("mp", 20 );
    me->receive_damage("ap", 20 );
    me->add("evil", random(-target->query("level"))-1 );
      me->add("evil", -(1 + rs_sk/5) );
    addexp=me->query_int()+me->query_sou()*5+target->query("level");
    me->improve_spell("recite-sutra",addexp);

    me->save();
    return 1;
}
int valid_learn(object me) { return 1; }

void spell_improved(object me)
{
    int g,b,c,addexp;

    b = me->query_spell("recite-sutra",1);
    c = me->query("spell/recite-sutra");
    g = me->query("gain_bonze_exp");

    if( b > g ) {
        addexp=b*b*me->query_int() - (int)me->query("evil")*20;
        tell_object(me,HIG "�A�]�w�g�ᦳ�߱o�A�o��F"+ addexp +"�I�g��ȡC\n"NOR);
        me->add("exp",addexp);
        me->set("gain_bonze_exp",b);
    }
    if(b > c && b % 15 == 0 && random(b) > 15 )
    {
        tell_object(me, HIC "�A�]�w�g�ӭץX���D�A�A�����z���ɤF�C\n" NOR);
        me->add("addition/int", 1);
        me->set("spell/recite-sutra",b);
    }
    me->save();
}
