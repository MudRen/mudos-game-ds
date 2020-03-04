//�����v purple-blood.c ����P
// -tmr 2007/10/28

#include <ansi.h>
inherit SKILL;
void delay(object me,int cost);
int exert(object me, object target, string arg)
{
    if(arg=="off" )
    {
        if(!me->query_temp("is_busy/purple-blood") ) return notify_fail("�A�{�b�èS���ϥΡi����L�j�C\n");
        message_vision("\n"HIW"$N�w�w���C�}�����A�ݰ_�ӤQ�����믫�C\n"NOR,me);
        me->delete_temp("is_busy/purple-blood");
        return 1;
    }
    if(me->is_ghost() ) return notify_fail("�A�٬O����C\n");
    if(me->is_fighting() ) return notify_fail("�A���b�԰��A�L�k�i����L�j�C\n");
    if(me->is_busy() ) return notify_fail("(�A���W�@�Ӱʧ@�٨S�������C)\n");

    if(me->query("ap") < 20 ) return notify_fail("�A�{�b�����l�����C\n");
    if( me->query("mp")>=me->query("max_mp") 
        && me->query("hp")>=me->query("max_hp") ) return notify_fail("�A�{�b���믫���p�w�g��F�A�p�F�C\n");

    if( sizeof(me->query_temp("is_busy")) ) return notify_fail("�A�{�b���b���C\n");
    if(!me->skill_active( "purple-blood",(: call_other, __FILE__, "delay", me ,5:), 5))
        return notify_fail("�A�����i����L�j���ʧ@�٨S�����C\n");
   
    message_vision(HIM"$N"HIM"�L�L�ӧ��A�B�_�i����L�j�ߪk�A��������w�wŢ�n�_�����C\n"NOR,me);
    me->set_temp("is_busy/purple-blood","�A���b�ϥΡi����L�j���A���ಾ�ʡC");
    me->start_busy(2);
    // me->start_call_out( (: call_other, __FILE__, "delay", me ,5:), 5);
    return 1;
}

void delay(object me,int cost)
{
    if(!me) return;
    if(!me->query_temp("is_busy/purple-blood") )
    {
        return;
    }

    if(me->query("ap") <20)      // ap ����
    {
        message_vision(MAG"$N"MAG"���l�ӷ��A�j�S�@�f����A�����i����L�j�C\n"NOR,me);
        me->delete_temp("is_busy/purple-blood");
        return;
    }

    // �P�ɸɺ� mp, hp
    if( me->query("mp") >=me->query("max_mp") 
        && me->query("hp") >=me->query("max_hp") )
    {
        message_vision(MAG"$N"MAG"�j�S�@�f����A���⨬�A�ݰ_�ӫD�`���믫�C\n"NOR,me);
        me->delete_temp("is_busy/purple-blood");
        return;
    }


    if(me->is_fighting())
    {
        message_vision(HIR"$N�ѩ��M��������A�����J�]�A�ӦR�F�@�f�A���⪺�A��C\n"NOR,me);
        me->receive_damage("hp", 7);
        me->delete_temp("is_busy/purple-blood");
        me->start_busy(1);
        return;
    }


        me->receive_damage("ap", me->query_int()/4);
    if( random(me->query_skill("purple-blood",1)+20) < 10 || random(9)==0 )
    {
        message_vision("$N���z�F�@�U�A���𴲶h�A���G���I�����J�]�F�C\n",me);
        me->receive_damage("hp", 5);
    }
    else
    {
        me->receive_heal("mp", 1 + (me->query_int()/3) + random(me->query_skill("purple-blood")/2) );
        me->receive_heal("hp", 1 + (me->query_int()/3) + random(me->query_skill("purple-blood")/2) );
        me->improve_skill("purple-blood",1 + random(1+me->query_int()/2));
    }
        me->skill_active( "purple-blood",(: call_other, __FILE__, "delay", me ,5:), 5);
}

int valid_learn(object me) { return 1; }
int practice_skill(object me) { return 1; }

