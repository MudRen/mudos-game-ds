// pwd.c
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if(!me->query_temp("invis"))
	{
		message_vision(HIC"$N�j�ۤ@�n:"HIY"����!!�X�ӧa!!!"HIC" ����ۤƬ��d�D�m�i���ѪŽĥh�C\n"NOR,this_player());
		me->set_temp("invis",(int)SECURITY_D->get_wiz_level(me));
		return 1;
	}
	
	if(me->query_temp("invis"))
	{
		message_vision(HIC"$N�����ά�M�X�{�b�A�����e..\n"NOR,me);
 		me->delete_temp("invis");
 		return 1;
	}
	return 0;
}	
	

