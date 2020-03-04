/*
�� �ӳ����� (moon-essence) - ���Z�жi���ޯ�

�ӳ�����O���Z�г̶������G�N�A��ҩ۳ꪺ�t��
�����������ڡA���Z�Ч̤l�i�H�q����W�V���³��ʽ�
���u�ӳ�����v�A�æ��æb�ۨ��餺�C�Q�Τӳ�����A���Z
�Ч̤l�i�H�ʰʤӳ����O�A�����o�ʩG�N�A��ĤH�@�ӱ���
���ΡC

�ޯ�C5�ťi�H�h����1�I�ӳ�����A�̦h�i�x�s25�I�C

Last update: Tmr 2008/07/22
*/

#include <ansi2.h>
        
#define SKILL_NAME "moon-essence"

inherit SSERVER;
inherit SKILL;

int cast(object me, object target)
{
        int point;
        point = me->query_temp("MOON_ESSENCE");
        tell_object(me, sprintf("�A�餺�æ�%2d�I�ӳ�����C\n", point) );
        return 1;
}

// �p��i�H�x�s������W��
int limitPoint(object me) {
        // �̦h25�I
        return me->query_spell(SKILL_NAME)/4;
}

// �O�_�i�H�A�W�[
void checkAdd(object me) {
        int points;
    if(me->query_spell("moon-essence") <1 ) return;
        if( me->query_temp("MOON_ESSENCE") > limitPoint(me) )
                return;
        points = 1 + me->query_spell("moon-essence")/33;
        tell_object(me, HBK"�A�q�t������W�V���X�ӳ�����C\n"NOR);
        me->add_temp("MOON_ESSENCE", points);
        me->improve_spell(SKILL_NAME, 1 + random(me->query_int()));
}

int checkUse(object me) {
        if(me->query_temp("MOON_ESSENCE")< 1) 
                return 0;
        
        // ���1�I
        me->add_temp("MOON_ESSENCE", -1);
        return 1;
}

