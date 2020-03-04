// File : "/cmds/wiz/putjail.c"
// Backup : "/cmds/wiz/putjail.bak"
// Rewrote By -Alickyuen@DS- on 2001-11-05

#include <ansi.h>
#define JAIL_ROOM "/open/always/ppl_jail"

inherit F_CLEAN_UP;

int main(object me, string str)
{
	object ob, where;
	string ppl;
	int i, num;

	if( !str ) return this_object()->help(me);

	if( sscanf(str, "%s because %d", ppl, num)!=2 )
		return this_object()->help(me);

	ob = LOGIN_D->find_body(ppl);

	if( !ob ) return notify_fail("�u�W�èS���o�ӤH�C\n");

        if( userp(me) && wiz_level(ob) >= wiz_level(me)) return notify_fail("�A�u��쵥�Ť�A�C���Ův�C\n");

	if( num > 7 || num < 1 )
		return this_object()->help(me);

	message("system","\n\n  [1;35m "+ob->name(1)+"�]���H�ϤF�C���W�h�ӳQ"+me->name(1)+"��i�F�ɪźʺ������f�P�C[0m\n\n",users());
	where=environment(ob);
	tell_room(where,"�ѪŤ��X�{�F�@�Ӥj�K����"+(string)ob->query("name")+"��F�_��, �M�᭸���F~~\n", ob);
	tell_object(ob,"�@���K����A��F�_��, ��M�A���e�@��....\n");
	if(where) ob->set("putjail_position",base_name(where));
	ob->set("out_of_power",1); // setting of no power in jail
	ob->move(JAIL_ROOM);
	if( userp(me) ) me->move(JAIL_ROOM);
	tell_object(me, "�A��"+(string)ob->query("name")+"���F�ʺ�.\n");
	tell_object(ob,".... ���ӮɧA�o�{�w�g�Q"+(string)me->query("name")+"���ʺ��ӤF.\n");
	tell_room(environment(ob),(string)ob->query("name")+"��M�X�{"+"�b�ʺ���\n",({me,ob}));
	ob->save();
	JAIL_ROOM->jail_time(ob, num);
	log_file("putjail",sprintf("[%s] %s go Jail by %s(%s) bcoz %d\n",ctime(time()),ob->name_id(1),me->name(1),getuid(me),num));

	return 1;
}

int help(object me)
{
write(@HELP
���O�榡 : putjail <�Y�H> because <��]�s�X>

�����O�i���A�N�Y�H���ʺ�, �A�ۤv�]�|�ǰe�ܺʺ���K�ݸܡC

��]�s�X�G
���^Multi	���^Robot	���^Bug		���^Flood
���^Foul	���^Quest	���^Other(1 hour)

���D���Ԩ�help guideline��
HELP
    );
    return 1;
}
