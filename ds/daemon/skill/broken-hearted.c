// Tmr 2007/04/14
// �X�z�@�o�T�d�\ (broken-hearted)      - �i���ޯ�
        
#include <ansi.h>
#define SKILL_NAME "�X�z�@�o�T�d�\\"
inherit SKILL;
inherit SSERVER;

void clear(object me);
                         
int exert(object me, object target, string arg)
{
    int damage,effect;
    int sk = me->query_skill("broken-hearted");
    if(!target) target = offensive_target(me);  // �ĤH
    if( !target )
        return notify_fail("�A�n��֨ϥΡH\n");
    if(me->query("ap") < 150)
                return notify_fail("�A�����l�����ϥX"+SKILL_NAME+ "\n");
    if(!me->is_fighting(target) )
                return notify_fail("�A�o�b�԰����~��ϥ�"+SKILL_NAME + "\n");
    if(me->query_skill("seven-love") < 90)
        return notify_fail("�ϥ�"+SKILL_NAME+"�ݭn����q�C�i���N�C\n");
    if(me->query_skill("thousand-hair") < 90)
        return notify_fail("�ϥ�"+SKILL_NAME+"�ݭn����q�T�d�дo���C\n");
    if( me->query_temp("BROKEN_HEARTED_DAMAGE") && userp(me) )
                return notify_fail("�A�u�ɶ����L�k�A�ϥ�"+SKILL_NAME+"�C\n");

    damage = me->query_damage() * 5/2; // 250%
    damage -= target->query_armor() + random(target->query_armor());
    damage = COMBAT_D->Merits_damage(me, target, damage, "bio");
    
    message_vision(MAG "\n$N�o�ʡu�X�z�@�o�T�d�\\�v�A�E�_���߲`�B���@�ѷT��...\n" NOR,me,target);
    message_vision(HIM "�o�ѷT��L���i��A���������e���Ӵd�[�A�N$n"HIM"�ιΥ]���I\n"NOR,me,target);

    // �����R��
    if( damage > 0 &&
            ( random(sk*2) > COMBAT_D->attack_factor(me, "whip")*10/15
            || random(sk*2) > -COMBAT_D->dodge_factor(target,"dodge") ) ) {
         message_vision(HIR "$n"HIR"�L�k�Ө���o�ѬX�z�d�\\���T��A�b���ߤW�y���L�k���Ϫ��ˮ`�I�I[" + damage +"]\n"
                       NOR,me,target);
        target->receive_damage("hp", damage, me);
                // �T�䦳busy���ĪG
                if( !userp(me) || random(100) < 30 + sk/2) {
                message_vision( HIB "\t�T�䤴�M��¶$n"HIB"�����Y�W�A$n"HIB"���T�éæa�y�_�\\�ӡC\n"NOR,me,target);
                        effect = 1 + sk/45;
                target->start_busy(effect);
                } else {
                target->start_busy(1);
                }
        me->start_busy(1);
        me->receive_damage("ap", 80, me);
        me->improve_skill("broken-hearted", 1 + random(me->query_con()) );
    } else {
            message_vision( CYN ""+target->query("name")+CYN"�b�D�`��檺���p�U�A�w�O�N�ۤw�����o�ѷT�䪺�v�T�C\n" NOR,target,me);
            me->start_busy(2);
    }
    me->set_temp("BROKEN_HEARTED_DAMAGE",1);
        if( (me->query_bar()+me->query_tec()) <= 12 )
                call_out("clear", 20-(me->query_bar()+me->query_tec()) , me);
        else
                call_out("clear", 8 , me);


    return 1;
}

void clear(object me)
{
    if(!me) return;
            tell_object(me,"�A�i�H�A�ϥ�"+SKILL_NAME+"�F�C\n");
    me->delete_temp("BROKEN_HEARTED_DAMAGE");
}

int improve_limite(object ob)
{
      return 100;
}


