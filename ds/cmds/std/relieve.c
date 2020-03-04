// relieve.c
#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
	object ob;
	
	seteuid(getuid(me));

	if(!arg)
		return notify_fail("�Ы��w��H!!\n");

	ob = present(arg, environment(me));
	if (!ob) ob = find_player(arg);
	if (!ob) ob = find_living(arg);
	if (!ob) return notify_fail("�o�̨S���o�ӤH!!\n");

	if( me->query_skill("relieve") < random(50) )
		return notify_fail("�A���ѱϦ�ʥ��ѤF�C\n");

	if( ob == me )
		return notify_fail("�A�ѱϧA�ۤv�F����?\n");

	if( !ob->is_fighting() )
		return notify_fail(ob->query("name")+"�ثe�èS�������H�b�԰�, �A�ѱϽ֪�?\n");
	if( me->is_ghost() )
		return notify_fail("\n�A�{�b�i�O���r�I���ѱϤH���H\n");
	if( me->is_busy() )
		return notify_fail("\n�����A�������䪺�ƦA���a�C\n");
	if( me->is_fighting_ob(ob) )
		return notify_fail("�A���b��"+ob->query("name")+"�԰��C...���h�ѱϥL��...\n");
	if( ob->is_fighting_ob(me) )
		return notify_fail(ob->query("name")+"���b��A�԰��C...���h�ѱϥL��...\n");

	message_vision(HIG"$N"HIG"�īi���V�e�ѱ�"HIG"$n"HIG"�T�T�T\n"NOR,me,ob);
	if( ! ob->relieve(me) )
		return notify_fail(me->query("name")+"�ѱ�"+ob->query("name")+"����ʥ��ѤF...\n");
	else
	{
		tell_object(ob,me->query("name")+"�X��ѱϤF�A�T\n");
		tell_object(me,"�ѱϦ��\\�F�T\n");
	}
	if( me->query("int")+me->query("level") < random(50) )
		me->improve_skill("relieve", random(3), 1);

	return 1;
}

int help(object me)
{
        write(@HELP
���O�榡 : relieve ��H

�o�O�ѱϪ����O�A�A�����n���ǲߡu�ѱϡv�o�ӧޯ�~��ϥΡC
��A�ѱϧA����H��A����Q�Ϫ̪��ĤH�N�|�����A�A�ӥB�A�@���u��ѱϤ@�H�C

HELP
    );
    return 1;
}

