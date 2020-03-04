// shout.c
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if (!arg) return notify_fail("�A�Q�n�j�s����?\n");
	if(me->query("creater")) return 0;
	if(!userp(me) && me->query("creater")) return 0;
	if( !wizardp(me) && userp(me))
	{
		if( me->query("talk_point")<10) return notify_fail("�A�{�b�f������, �n���@�U�~���O�𻡸ܳ�!\n");
	 	if(me->query("mp")< 15)
			return notify_fail("�A����O����, �S���������O��ۥs�C\n");
		me->add("mp",-15);
		me->add("talk_point",-10);
	}
	if(wizardp(me) && userp(me) )
	{
		if(sscanf(arg, "%s -beep", arg) == 1)
		{
			message("system","\n  "+HIC+me->name(1)+HIC+"�o�G���q��!! ����`�N!!!\n\n"NOR,users());
			shout( "    "+HIG+me->name(1) + HIG"�ϫl�j�ۡR "HIW + arg + "\n\n"NOR);
			write(HIG"    �A�ϫl�j�ۡR "+HIW+ arg + "\n\n"NOR);
		MOTD_D->announce(me->query("id")+"@DS", arg);
			return 1;	
		}
	}
	shout( HIR+me->name() + HIR"�ϫl�j�ۡR" + arg + "\n"NOR);
	write(HIR"�A�ϫl�j�ۡR" + arg + "\n"NOR);
	return 1;
}
int help(object me)
{
  write(@HELP
���O�榡 : shout <�T��>
 
�o�ӫ��O���A�N <�T��> �ǰe�X�h, �Ҧ����b�C�������H��
�|ť���A����.
 
see also : tune
HELP
    );
    return 1;
}
 
