/*
   Editor-Js@DS
   SK : �K���������j�}
   �γ~: �s�y�C�ʶˮ`
*/
// Last update Tmr 2006/10/12
// �վ�ˮ`�O�����A�[�W�u�F���T�I��v
        
#include <ansi.h>
#define SKILL_NAME "���j�}"   
inherit SKILL;
inherit SSERVER;

string *actions=({
                     "�E�����y","�ꥴ���y","��L","�㥴","½���p��","��L"
                 });

void clear(object me);
                         
int exert(object me, object target, string arg)
{
        int damage;
    int sk = me->query_skill("six_open");
        if(!target) target = offensive_target(me);  // �ĤH
    if( !target )
        return notify_fail("�A�n��֨ϥX"+SKILL_NAME+"�H\n");
    
    if(me->query_temp("SIX_OPEN_DAMAGE") )
        return notify_fail("�A�u�ɶ����L�k�A�ϥΤ��j�}�C\n");
    
    if(me->query("ap") < 200) return notify_fail("�A�����l�����ϥX"+SKILL_NAME+"\n");
    if(!me->is_fighting()) return notify_fail(SKILL_NAME+"�O�@�ؾ԰��ޯ�!\n");
    if(me->query_skill("bagi_fist")<100)
        return notify_fail("�ϥ�"+SKILL_NAME+"�ݭn����q�K�����k�C\n");
    if(me->query_skill("horse-steps")<100)
        return notify_fail("�ϥ�"+SKILL_NAME+"�ݭn�`�p���K���㰨�C\n");
    if(me->query_skill("unarmed")<100)
        return notify_fail("�ϥ�"+SKILL_NAME+"�ݭn���m���Ť�i���ޥ��C\n");
    if(me->query_skill("parry")<70)
        return notify_fail("�ϥ�"+SKILL_NAME+"�ݭn���m���Z���۬[�C\n");

     damage = me->query_damage()*2;
    damage -= target->query_armor() + random(target->query_armor());
        damage = COMBAT_D->Merits_damage(me, target, damage, "bar");
    
    message_vision(HIG "\n$N�ϥX�u���j�}�v�j�P���l�A�@�ѱj�l������������l�|���ӥX...\n" NOR,me,target);
    message_vision(HIG "$N�@��"+ HIB "�u"+ actions[random(sizeof(actions))] + "�v"+HIG"�A²��Ө��t�a��������l�������V$n"HIG"�ݫe�n�`�I�I\n"NOR,me,target);

    // �����R��
    if( damage > 0 &&
            ( random(sk*2) > COMBAT_D->attack_factor(me,"unarmed")*10/15
            || random(sk*2) > -COMBAT_D->dodge_factor(target,"dodge") ) ) {
          message_vision(HIR "$n"HIR"�{�����ΡA�����Q$N"HIR"�����ݤf�A�ذդ@�n�T�A���O�ذ��H�����n���I�I[" + damage +"]\n"
                       NOR,me,target);
        target->receive_damage("hp",damage,me);
          target->start_busy(1);
        me->start_busy(1);
        me->receive_damage("ap", 50, me);
        me->improve_skill("six_open",1 + random(me->query_con()) );
        // �[�Wcondition
                  if(sk>=10) target->apply_condition("six_open_force", sk/10);
    } else {
        switch(random(3))
        {
        case 0:
            message_vision(HIW ""+target->query("name")+"�b�d���@�v���ڡA�{�}�F"+me->query("name")+"�r�P������....\n" NOR,target,me);
            me->start_busy(2);
            break;
        case 1:
            message_vision(HIW ""+target->query("name")+"�������a���F�}�h�A���}�F�o�@�������....\n" NOR,target,me);
            me->start_busy(2);
            break;
        case 2:
            message_vision(HIW ""+target->query("name")+"�u�z�v�@�n�y�s�A����Y½���u�F�}�h�A���}�F�o�����I�ǭP�R������...\n" NOR,target,me);
            me->start_busy(2);
            break;
        }
    }
        me->set_temp("SIX_OPEN_DAMAGE",1);
          if( me->query_bar() <= 5 )
                call_out("clear", 20-me->query_bar()*2 , me);
            else
                call_out("clear", 8 , me);

    return 1;
}

void clear(object me)
{
    if(!me) return;
        tell_object(me,"�A���e�]�ϥΤ��j�}�ҳy��������ˮ`�A�w�g��_�F�C\n");
    me->delete_temp("SIX_OPEN_DAMAGE");
}
int improve_limite(object ob)
{
      return 100;
}

