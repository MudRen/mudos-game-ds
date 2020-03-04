//mage_steps.c
#include <ansi.h>
inherit SKILL;
void delay(object me,int cost);
string *dodge_msg = ({
                         HIM"$n���λ����@��A$N���������šC\n"NOR,
                         HIM"$n�����@�n�̪Ů����A�b$N���e�����C\n"NOR,
                         HIM"$n�}�B�L���A���M�P���{�L�@�ۡC\n"NOR,
                         HIM"$n���ηL�L�@�ʡA�{�L$N�������C\n"NOR,
                         HIM"$n���O�@���A�U�D�}�v�N$N���������צ�\n"NOR,
                         HIM"$n���H�N��A���Φp�v�L�ܰ{�L�Ҧ�������\n"NOR,
                     });



int exert(object me, object target, string arg)
{
    string msg;

    if(arg=="off" )
    {
        if( me->query_skill_mapped("dodge")!="windmove")
            return notify_fail("�A�èS���ϥέ���B�C\n");
        me->map_skill("dodge");
        me->reset_action();
        message_vision("\n"HIW"$N�S��_�^��Ӫ��t�פF�C\n"NOR,me);
        write("�ޯ�[����B]�w�����C\n");
        return 1;
    }

    if(me->query_skill("dodge")<20) return notify_fail("�A�����\\��¦�����L�k�ϥέ���B�C\n");
    if(me->query_skill_mapped("dodge")=="windmove")
        return notify_fail("�A���b�ϥέ���B�C\n");
    if(me->query("mp")<10 || me->query("hp")<10) return notify_fail("�A�����骬�p�L�k�ϥέ���B�C\n");

if(!me->skill_active( "windmove",(: call_other, __FILE__, "delay", me ,2:), 10))
        return notify_fail("�A�W�@�Ӱʧ@�٨S�����C\n");

    me->map_skill("dodge", "windmove");
    me->reset_action();
    message_vision("\n"HIW" �y�I���z $N�`�l�@�f��, �}�l�I�i�y����B�z, $P���}�B�ܱo�Q�����֡C\n"NOR,me);
    me->add("mp", -2);
    me->start_busy(1);
    //me->start_call_out( (: call_other, __FILE__, "delay", me ,2:), 10);
    return 1;
}

void delay(object me,int cost)
{
    if(!me) return;
    if(me->query_skill_mapped("dodge")!="windmove")
    {
        return;
    }
    if(me->query("ap")<cost+1)
    {
        me->map_skill("dodge");
        me->reset_action();
        message_vision("\n"HIW"$N�S��_�^��Ӫ��t�פF�C\n"NOR,me);
        tell_object(me,"�A����O�����L�k�~��ϥ�[����B]�C\n");
        return ;
    }
    me->receive_damage("ap", cost);
    //me->start_call_out( (: call_other, __FILE__, "delay", me ,cost:), 10);
me->skill_active( "windmove",(: call_other, __FILE__, "delay", me ,cost:), 10);
}

int valid_learn(object me) {	return 1;	}

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me) {	return 1; }
