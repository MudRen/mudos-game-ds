// �o���ɮרS���Y��!! �Цۤv���n�Y��
// �ڧ�F�X��bug, ���O�٬O������bug. �[�o�a!
// delay() �n���X��. �_�h�I�k�������|delay

#include <ansi.h>
inherit SSERVER;
inherit SKILL;
int cast(object me, object target)
{
    int inn,sk,cost,lev;	//�Ф��n�� in ���ܼ�, �ڧאּinn
    int lv,mk,lck;
    string who,name;

    if(!me) me=this_player();
    inn=me->query_int();	//luky fix
    lev=me->query("level");
    mk=me->query_spell("mindkill");
    sk=mk/10+1;
    cost=50;

    /* �ɶq���n���k�N�u���԰����, �����ʪk�N�u�n�[�W�̫�X����NPC�����Y�i.
     if ( !me->is_fighting())
        return notify_fail("�o�k�N�u���԰��ɤ~��ϥΡC\n");
    */
    if(environment(me)->query("no_cast")) return notify_fail("�o�̤���I�k�C\n");
    if ( !target ) target = offensive_target(me);
    if ( !target )	return notify_fail("�A�n��֬I�i�o�Ӫk�N�S\n");

    if(!me->can_fight(target))
        return me->can_fight(target);

    if( (int)me->query("mp") <  cost )
        return notify_fail("�A���]�O�����C\n");
    me->add("mp", -cost);
    message_vision(HIG"$N�����ۤv���믫.."+
                   "�}�l�߯��k�@�A�믫�O�q�R������\n\n"NOR,me);

    me->start_busy(2);
    call_out("delay",3,target,me,mk);
    return 1;
}

int delay(object target,object me,int mk)
{
    int tlv,inn,lv,sk,i,damage;
    //�bdelay����,�n�Ҽ{�����ܤ�
    if(!me) return 0;					//1.me �i�঺�`�άO���u
    if(!target) return notify_fail("�ؼЮ����F�C\n");	//2.target�i�঺�`�άO���u
    if( environment(me) != environment(target) )		//3.�ؼХi��|���}.
        return notify_fail("�ؼ����}�F�A���I�k�d��C\n");
    sk=mk/20+random(mk/20)+1;
    inn=me->query_int();
    lv=me->query("level");
    message_vision(HIG"��M$N����@�X,�j�ܤ@�n�I "
                   +HIC"��� ���F�������N�����\n\n"NOR,me);

    tlv=target->query("level");
    if(sk>10) sk = 10;
    if( lv + random(inn) + inn > tlv+ random(inn) )
    {
        for ( i=0 ; i <= sk ; i++)
        {
            message_vision(HIG"$N"HIG"���F���N����$n"HIG"�����F�I "NOR,me,target);
            damage=( inn +random(mk*2) ) * random(2); //�o�@��X�n�n�n�Q�Q�A�g�L
            damage -= target->query_sheild();	//query_shield()�|�Ǧ^�ӤH�����]�k���m�O
            if ( damage > 0)
            {
                message_vision(HIY"�y��$N"HIW+damage+HIY"�I���ˮ`�I�I�I�I\n"NOR,target);
                // �W�[�����ˮ`���v�T
                damage = COMBAT_D->Merits_damage(me,target,damage,"sou");
                target->receive_damage("hp", damage, me );
            }
            else
                message_vision(GRN"$N"GRN"���F���w�A�N�F���u�}�I\n"NOR,target);
        }
    }
    COMBAT_D->report_status(target);	//�[�W�o��i�H���target�����d���p
    target->start_busy(3);
    if( inn>random(20) )
    {
        me->improve_spell("mindkill",inn+random(20));
    }
    if(!target->is_fighting(me)) target->kill_ob(me);	//�����ʪk�N�[�W�o���
    if(!me->is_fighting(target)) me->kill_ob(target);	//
    return 1;
}