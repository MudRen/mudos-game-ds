// pwd.c
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if(!me->query_temp("invis"))
	{
		message_vision(HIC"$N大喊一聲:"HIY"光爪!!出來吧!!!"HIC" 身體幻化為千道彩虹往天空衝去。\n"NOR,this_player());
		me->set_temp("invis",(int)SECURITY_D->get_wiz_level(me));
		return 1;
	}
	
	if(me->query_temp("invis"))
	{
		message_vision(HIC"$N的身形突然出現在你的眼前..\n"NOR,me);
 		me->delete_temp("invis");
 		return 1;
	}
	return 0;
}	
	

