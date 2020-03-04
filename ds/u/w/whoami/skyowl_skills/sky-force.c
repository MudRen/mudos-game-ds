/*
���\ - �T�M�E�] (sky-force)

       ���U�ޯ� �ޯ�C����10�ӵ��� skyowl-dagger ���¤O�]�|�V�W���ɤ@�ӵ���

           sk 40 �i�ϥίS��N�ۨ� 2/5 �������O�ഫ�����m�O 
           sk 80 �i�ϥίS��N�ۨ� 2/5 �����m�O�ഫ�������O
*/

#include <ansi.h>
inherit SKILL;

void armor(object me, int effect)
{
    if(!me) return;
    if(!me->query_temp("sky-force/power_up") ) return;
    message_vision(HIG "$N�@�n�C�S�A�����ɰ_���٦׫�_�F���`�����A�C\n"NOR,me);
    me->add_temp("apply/damage",effect);
    me->add_temp("apply/armor",-effect);
    me->delete_temp("sky-force/armor");
    return;
}

void power_up(object me, int effect)
{
    if(!me) return;
    if(!me->query_temp("sky-force/power_up") ) return;
    message_vision(HIG "$N�@�n�C�S�A�����ɰ_���٦׫�_�F���`�����A�C\n"NOR,me);
    me->add_temp("apply/damage",-effect);
    me->add_temp("apply/armor",effect);
    me->delete_temp("sky-force/power_up");
    return;
}

int exert(object me,object target, string arg)
{
    int sk = me->query_skill("sky-force"),
        force = me->query_skill("force"),
        damage = me->query_damage(),
        armor = me->query_armor(),
        x = 0;
//sk 40 �i�ϥίS��N�ۨ� 2/5 �������O�ഫ�����m�O 
    if(arg=="armor")
    {
        if( sk < 40 ) return notify_fail("�A���T�M�E�]�٤������m�A�L�k�I�i�u�K�_�Z�v�C \n");
        if(me->query("ap") < 70  || me->query("hp")<120 ) return notify_fail("�A�ثe�����A�L�k�I�i�u�K�_�Z�v�C\n");
        if(me->query_temp("sky-force/power_up")) return notify_fail("�A�w�g�b�I�i�u�K�_�Z�v�C\n");
        if(me->query_temp("sky-force/armor")) return notify_fail("�A�w�g�b�I�i�u�K�_�Z�v�C\n");
        
        message_vision(HIG "$N"+HIG+"�V�e�r�M��F�@�j�B�A�z�ܤ@�n�A���l�ϩ��b�@�������j�F�_�ӡA��S�����A�����W�U�����`�͹ͭ��a�T�Ӥ����C\n"NOR, me);
        me->improve_skill("sky-force",1+random(force/3)+me->query_int()/4 );
        me->improve_skill("force",1+random(5+me->query("level"))+me->query_int()/4 );
        me->receive_damage("hp",100);
        me->receive_damage("ap",50);

        x = damage*2/5;
        me->set_temp("sky-force/armor", x);
        me->add_temp("apply/damage", -x );
        me->add_temp("apply/armor", x );
        me->start_busy(2);
        me->skill_active( "sky-force",(: call_other, __FILE__, "armor", me, me->query_temp("sky-force/armor") :), 180);
        return 1;
    }
//sk 80 �i�ϥίS��N�ۨ� 2/5 �����m�O�ഫ�������O
    if(arg=="power_up")
    {
        if( sk < 80 ) return notify_fail("�A���T�M�E�]�٤������m�A�L�k�I�i�u�K�_�Z�v�C \n");
        if(me->query("ap") < 70  || me->query("hp")<120 ) return notify_fail("�A�ثe�����A�L�k�I�i�u�K�_�Z�v�C\n");
        if(me->query_temp("sky-force/power_up")) return notify_fail("�A�w�g�b�I�i�u�K�_�Z�v�C\n");
        if(me->query_temp("sky-force/armor")) return notify_fail("�A�w�g�b�I�i�u�K�_�Z�v�C\n");
        
        message_vision(HIG "$N"+HIG+"�V�e�r�M��F�@�j�B�A�z�ܤ@�n�A���l�ϩ��b�@�������j�F�_�ӡA��S�����A�����W�U�����`�͹ͭ��a�T�Ӥ����C\n"NOR, me);
        me->improve_skill("sky-force",1+random(force/3)+me->query_int()/4 );
        me->improve_skill("force",1+random(5+me->query("level"))+me->query_int()/4 );
        me->receive_damage("hp",100);
        me->receive_damage("ap",50);

        x = armor*2/5;
        me->set_temp("sky-force/power_up", x);
        me->add_temp("apply/damage", x );
        me->add_temp("apply/armor", -x );
        me->start_busy(2);
        me->skill_active( "sky-force",(: call_other, __FILE__, "power_up", me, me->query_temp("sky-force/power_up") :), 180);
        return 1;
    }
    return notify_fail("�T�M�E�]�� power_up �\\��C\n");

}

int valid_learn(object me){ return 1; }
int practice_skill(object me){ return 1; }

void skill_improved(object me)
{
    int b,c;
    b = me->query_skill("sky-force");
    c = me->query("skill/sky-force");//luky

    if( b % 10==9 && b > c){
        if(random(2)){
            tell_object(me,HIY "�A�����z�����F�I\n" NOR );
            me->add("addition/int", 1);
        } else {
            tell_object(me,HIY "�A����责���F�I\n" NOR );
            me->add("addition/con", 1);
        }
        me->set("skill/sky-force",b);
    }
    me->save();
    return;
}

int improve_limite(object me)
{
    if( !me->query("quest/skyowl/sky-force") ) { return 75; }
    else { return 100; }
}



