// �Ѥ����(Sky-air) by cominging and sexking
#include <ansi2.h>
inherit SKILL;
void delay(object me, object weapon, int flag);
void delay1(object me);
void end(object me, int x);
string *hara_msg = ({
  HIR"\n\n$N�N$n���J�a��,���W����,���ⴤ��,�ǳ��z�o"HIC"[�Ѥ����]"HIR"�I�I�I\n\n"NOR,
  HIR"\n\n$N�ݰ_�ӵh�W�U��,�Ⲵ�o��,���R��q��,���G�w�ֳQ���]��\n\n"NOR,
  HIR"\n\n������$N�C�}����,���ɨ��W�w�]�е��Ŧ⪺��V-"HIC"[�Ѥ����]"HIR"�I�I�I\n\n"NOR,
});
int exert(object me, object target, string arg)
{
        int minus_hp = me->query("hp")/10*5,
        minus_ap = me->query("ap") / 10*2,
        sk = me->query_skill("hara_kiri"),
        max_hp = me->query("max_hp"),
        max_ap = me->query("max_ap"),
        damage = me->query_damage(), x;
        object weapon;
        if( !objectp(weapon=me->query_temp("weapon")) )
                return notify_fail("�A�o�ǳƤ@��M�~��޵o�X�Ѥ����\n");
        if( weapon->query("skill_type") != "blade" )
                return notify_fail("�u���⤤���M�~��޵o�X�Ѥ����\n");
        if( me->is_busy() )
                return notify_fail("�A���b���I\n");
        if( me->query_bar() < 1) 
                return notify_fail("�A�~�ʤ���,�L�k�ϥX�Ѥ����C\n");
        if(me->query_temp("cccc")==1) return notify_fail("�A�w�g����"HIC"�Ѥ����"HIR"���]�ФF�C\n");
        
        x = (int)(sk*minus_hp/(200-(sk/2)))/30*(sk/15)+random(minus_ap/50+me->query_bar());
        if( x > 80 ) x = 80+random(4);
        if( x < 1 ) x = 1+random(3);
        me->add_temp("apply/damage", x);
        me->add_temp("cccc",1);
        if( me->query_armor() < (max_hp/(30+(sk/10))+x) )
        {
                me->set_temp("skills/hara_kiri_armor", me->query_armor());
                me->add_temp("apply/armor", -(me->query_armor()));
        }
        else
        {
                me->set_temp("skills/hara_kiri_armor", max_hp/(30+(sk/10))+x);
                me->add_temp("apply/armor", -(max_hp/(30+(sk/10))+x) );
        }
        me->start_busy(5); //add by sexking @_@ cominging 
        me->receive_damage("ap", minus_ap, COMBAT_D);
        me->receive_damage("hp", minus_hp, COMBAT_D);
        call_out("delay", 1, me, weapon, 0);
        call_out("end",20, me, x);
        return 1;
}
void delay(object me, object weapon, int flag)
{
        if( !me ) return;
        switch(flag)
        {
                case 0:
                case 1:
                case 2:
                        message_vision(hara_msg[flag] , me, weapon);
                        call_out("delay", 1, me, weapon, flag+1);
                        break;
                case 3:
                        tell_object(me, NOR HIR"... �A�Pı�餺�m��..�O�q�w�W�j�F����.."NOR);
                        me->set_temp("block_msg", 1);
                        call_out("delay1", 0, me);
                        call_out("delay", 2, me, weapon, 4);
                        break;
                case 4:
                        me->delete_temp("block_msg", 1);
                        tell_object(me, HIR"....\n\n");
                        message_vision(HIR"$N����F"HIC"�Ѥ����"HIR"���]��..�����O�j�j���W�[�I�I�I\n"NOR, me);
                        break;;
                default:
                        tell_object(me, BEEP HIR"[error]: �ǤJ���~,�гq���Ův�ץ�.\n");
                        break;
        }
        return;
}
void delay1(object me)
{
        if( !me ) return;
        tell_object(me, HIR"....");
}

void end(object me, int x)
{
        if( !me ) return;
        me->add_temp("apply/damage", -x);
        me->add_temp("apply/armor", me->query_temp("skills/hara_kiri_armor"));
        me->add_temp("cccc",-1);
        me->delete_temp("skills/hara_kiri_armor");
        message_vision(HIY"�H�ۮɶ����y�u, $N��"HIC"�Ѥ����"HIY"���Ŧ��V�]�������h....\n"NOR, me);
        return;
}
int valid_learn(object me) { return 1; }
int practice_skill(object me) { return 1; }
