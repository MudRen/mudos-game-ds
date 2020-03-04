// reboot.c

#include <login.h>
#include <obj.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string wiz_status;
	object npc;

	if( me != this_player(1) ) return 0;
	
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
		return notify_fail("�u�� (arch) �H�W���Ův�~�୫�s�Ұ�" + MUD_NAME + "\n");

	seteuid(getuid());
	npc = new(NPC_REBOOT);
	npc->set("no_kill",1);
	npc->move(START_ROOM);
	npc->start_shutdown();
	// ������
	log_file("static/reboot","Reboot by "+me->query("id")+" at "+ctime(time())+"\n");

	write("Ok�C\n");

	return 1;
}

int help (object me)
{
        write(@HELP
���O�榡: reboot
 
���s�_�ʹC��, �t�η|�}�l�˼ƭp��, �Q�������᭫�s�_�ʡC
 
HELP
);
        return 1;
}
 
