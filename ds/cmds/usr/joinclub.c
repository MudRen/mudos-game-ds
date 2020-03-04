// hp cmds
 
#include <ansi.h>
 
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        string *club,id;

        if(!arg) return notify_fail("�A�n�V�֥ӽФJ�����S\n");
        ob = present(arg, environment(me));
	if(!ob || ob==me ) return notify_fail("�o�̨S���o�ӤH�C\n");
	if(!wizardp(me))
	{
		if( !userp(ob) || wizardp(ob) ) return notify_fail("�u�缾�a�ӽ������C\n");
	
		club = CLUB_D->find_player_club(getuid(me));
		if(sizeof(club)>1)  return notify_fail("�A�w�g�[�J"+club[0]+"�F�C\n");
		club = CLUB_D->find_player_club(getuid(ob));
		if( sizeof(club)<1 ) return notify_fail("�����G�èS���ѥ[���|�C\n");
	}
	id = ob->query("id");
	if(me->query_temp("joinclub") == id) return notify_fail("�A�w�g�ӽйL�F, ��西�b�Ҽ{���C\n");
	message_vision("$N�����V$n���X�[�J���|���n�D�C\n",me,ob);
	tell_object(ob,"�p�G�A�P�N���[�J, �Х� accept "+me->query("id")+" ���O���L�J���C\n");
	me->set_temp("joinclub",id);
	return 1;
}
                          
int help(object me)
{
        write(@HELP
���O�榡 : 
           joinclub <��H�W��> 
           
�o�ӫ��O�i�H�ШD��覬�A�J���|�C

see also : score
HELP
    );
    return 1;
}

