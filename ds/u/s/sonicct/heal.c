//By SonicCT&Mulder
//1999.10.18
#include <ansi.h>
inherit SKILL;
void delay(object me,int cost);
int exert(object me, object target, string arg)
{
        if(arg=="off" )
        {
		if(!me->query_temp("is_busy/heal") ) return notify_fail("�A�{�b�èS�������C\n");
	        message_vision("\n"HIW"$N�w�w���C�}�����A�ݰ_�ӤQ�����믫�C\n"NOR,me);
		me->delete_temp("is_busy/heal");
                return 1;
        }
	if(me->is_ghost() ) return notify_fail("�A�٬O����C\n");
	if(me->is_fighting() ) return notify_fail("�A���b�԰��A�L�k�����C\n");
	if(me->is_busy() ) return notify_fail("(�A���W�@�Ӱʧ@�٨S�������C)\n");
	if(me->query("hp")>=me->query("max_hp") ) return notify_fail("�A�{�b���ͩR���p�w�g��F�A�p�F�C\n");
	if( sizeof(me->query_temp("is_busy")) ) return notify_fail("�A�{�b���b���C\n");
	if(!me->skill_active( "heal",(: call_other, __FILE__, "delay", me ,5:), 5))
        return notify_fail("�A���������N���ʧ@�٨S�����C\n");
        message_vision("\n"HIW"$N�L���ӧ��A�P��ۤv�������b����W�C�ʡA�}�l�i�J�������A�C\n"NOR,me);
        me->set_temp("is_busy/heal","�A���b�������ಾ�ʡC");
        me->start_busy(5);
       return 1;
}

void delay(object me,int cost)
{
        if(!me) return;
        if(!me->query_temp("is_busy/heal") )
        {
	         return;
        }

        if(me->query("hp")>=me->query("max_hp"))
        {
	        message_vision("\n"HIW"$N�w�w���C�}�����A�ݰ_�ӤQ�����믫�C\n"NOR,me);
		me->delete_temp("is_busy/heal");
		return;
        }
        
        if(me->is_fighting())
        {
	        message_vision("$N�ѩ��M��������A�����J�]�A�ӦR�F�@�f�A��C\n"NOR,me);
		me->receive_damage("hp",5);
		me->delete_temp("is_busy/heal");
		me->start_busy(1);
		return;
        }

        
        if( random(me->query_skill("heal",1)+20) < 10 || random(10)==0 )
        {
        	message_vision("$N���f�F�@�U�A���Y�j���A���G���I�����J�]�F�C\n",me);
                me->receive_damage("hp",10);
	}
	 else
	{
		me->receive_heal("mp", 3+(me->query_int()/2)+random(me->query_skill("heal")));
	 	me->receive_heal("hp", 5+(me->query_con()/2)+random(me->query_skill("heal")));
     		me->receive_heal("ap", 3+(me->query_dex()/2)+random(me->query_skill("heal")));
        	me->improve_skill("heal",1 + random(1+me->query_int()/2));
	}

        me->skill_active( "heal",(: call_other, __FILE__, "delay", me ,5:), 5);
}

int valid_learn(object me) { return 1; }
int practice_skill(object me) { return 1; }
