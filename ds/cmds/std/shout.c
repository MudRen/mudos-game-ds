// shout.c
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if (!arg) return notify_fail("你想要大叫什麼?\n");
	if(me->query("creater")) return 0;
	if(!userp(me) && me->query("creater")) return 0;
	if( !wizardp(me) && userp(me))
	{
		if( me->query("talk_point")<10) return notify_fail("你現在口乾舌燥, 要等一下才有力氣說話喔!\n");
	 	if(me->query("mp")< 15)
			return notify_fail("你的體力不夠, 沒有足夠的力氣喊叫。\n");
		me->add("mp",-15);
		me->add("talk_point",-10);
	}
	if(wizardp(me) && userp(me) )
	{
		if(sscanf(arg, "%s -beep", arg) == 1)
		{
			message("system","\n  "+HIC+me->name(1)+HIC+"發佈緊急通知!! 全體注意!!!\n\n"NOR,users());
			shout( "    "+HIG+me->name(1) + HIG"使勁大喊﹕ "HIW + arg + "\n\n"NOR);
			write(HIG"    你使勁大喊﹕ "+HIW+ arg + "\n\n"NOR);
		MOTD_D->announce(me->query("id")+"@DS", arg);
			return 1;	
		}
	}
	shout( HIR+me->name() + HIR"使勁大喊﹕" + arg + "\n"NOR);
	write(HIR"你使勁大喊﹕" + arg + "\n"NOR);
	return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : shout <訊息>
 
這個指令讓你將 <訊息> 傳送出去, 所有正在遊戲中的人都
會聽見你的話.
 
see also : tune
HELP
    );
    return 1;
}
 
