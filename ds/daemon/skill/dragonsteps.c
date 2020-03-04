//mage_steps.c
#include <ansi.h>
inherit SKILL;
void delay(object me,int cost);
string *dodge_msg = ({
                         "$n���Τ@�̡A�ϥX�u�P�s�{�v�{�}�F$N���ۦ��C\n",
                         "$n�a���ϥX�u�ĤE�ѡv���L�F$N�������C\n",
                         "$n�B�k�H����A�@�ۡu�C�|��v���}�F$N�������C\n",
                         "$n�}�U�@�ʡA�u�ʰ��[�v�@�۰{�}�F$N����աC\n",
                     });
int exert(object me, object target, string arg)
{
    string msg;

    if(arg=="off" )
    {
        if( me->query_skill_mapped("dodge")!="dragonsteps")
            return notify_fail("�A�èS���ϥιC�s�B�C\n");
        me->map_skill("dodge");
        me->reset_action();
        message_vision("\n"HIW"$N���U�F$N���}�B�C\n"NOR,me);
        write("�ޯ�[�C�s�B]�w�����C\n");
        return 1;
    }

    if(me->query_skill("dodge")<40) return notify_fail("�A���a�D�{�ׯ�O�٤����ϥιC�s�B�C\n");
    if(me->query_skill_mapped("dodge")=="dragonsteps")
        return notify_fail("�A���b�ϥιC�s�B�C\n");
    if(me->query("mp")<40 || me->query("hp")<40) return notify_fail("�A�����骬�p�L�k�ϥιC�s�B�C\n");

if(!me->skill_active( "dragonsteps",(: call_other, __FILE__, "delay", me ,5:), 5))
        return notify_fail("�A���_�C�s�B���ʧ@�٨S�����C\n");

    me->map_skill("dodge", "dragonsteps");
    me->reset_action();
    message_vision("\n"HIG"$N�}�l�I�i�C�s�B, ���ΰ��W�p�s�뭸�a�F�ƤU�C\n"NOR,me);
    me->add("mp", -5);
    me->start_busy(2);
    //me->start_call_out( (: call_other, __FILE__, "delay", me ,2:), 10);
    return 1;
}

void delay(object me,int cost)
{
    if(!me) return;
    if(me->query_skill_mapped("dodge")!="dragonsteps")
    {
        return;
    }
    if(me->query("ap")<cost+15)
    {
        me->map_skill("dodge");
        me->reset_action();
        message_vision("\n"HIW"$N��M�C�F�U�ӡC\n"NOR,me);
        tell_object(me,"�A����O�����ϥιC�s�B�F�C\n");
        return ;
    }
    me->receive_damage("ap", cost);
    //me->start_call_out( (: call_other, __FILE__, "delay", me ,cost:), 10);
me->skill_active( "windmove",(: call_other, __FILE__, "delay", me ,cost:), 5);
}

int valid_learn(object me) {	return 1;	}

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me) {	return 1; }
int improve_limite(object ob)
{
    int a;
    a=ob->query_dex();
    a=60+a;
    return a;
}
