/* �ⶳ�B�k(reachcloud-steps)
 *  
 * Advanced Thief Dodge
 *
 */
#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
                         NOR"\n$n�ϥX�u�����ƴ��v�A�����ƥG���w�A�ϱo$N�������������šC\n"NOR,
                         NOR"\n$n�a���@�D�A�ϥX�u�ۼv�g�ܡv�A$n�H�ײ��L�k�ݲM����H�t�׸��פF$N�������C\n"NOR,
                         NOR"\n$n�ϥX�u�����L�w�v�A���k��֡A�|�P�S�p�g���jŧ�A$n���Τ@���{�}�F$N�������C\n"NOR,
                         NOR"\n�u��$n���v���ְ{�ʡA�ϥX�u�涳�y���v�A$n�����v�p�M�󭸳u�@�ˡA�{�}�F$N�����C\n"NOR,

                     } );

int exert(object me, object target, string arg)
{

    if(arg=="off" )
    {
        if( me->query_skill_mapped("dodge")!="reachcloud-steps")
            return notify_fail("�A�èS���ϥΡu�ⶳ�B�k�v�C\n");
        me->map_skill("dodge");
        me->reset_action();
        write("�ޯ�u�ⶳ�B�k�v�w�����C\n");
        return 1;
    }

    if(me->query_skill("dodge")<20)
        return notify_fail("�A�����\\��¦�����L�k�ϥΡu�ⶳ�B�k�v�C\n");
    if(me->query_skill_mapped("dodge")=="reachcloud-steps")
        return notify_fail("�A�w�g�b�ϥΡu�ⶳ�B�k�v�C\n");
    if(me->query("ap")<10 || me->query("hp")<10)
        return notify_fail("�A�ثe�����骬�p�L�k�ϥΡu�ⶳ�B�k�v�C\n");
    me->map_skill("dodge", "reachcloud-steps");
    me->reset_action();
    message_vision(HIC"$N�����Y�СA�F���a½�F�X�ӭo��A�}�l�I�i�_�ⶳ�B�k�C\n"NOR,me);
    me->receive_damage("ap",10);
    me->start_busy(1);
    return 1;
}

int valid_learn(object me) {    return 1;       }
string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me) { return 1; }
int improve_limite(object ob)
{
    return 100;  // �i�H�ɨ�100�� by -Acme-
/*
    int a=ob->query_skill("reachcloud-steps");
    a=a+ob->query_int();
    if(a > 80) a=80;
    return a;
*/
}
