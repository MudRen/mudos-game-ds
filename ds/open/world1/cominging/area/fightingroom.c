#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "���a�v�޳�");
	set("long",@LONG
�o�O�B�F���������a�v�޳��A�b�o�̦��\�h�w�ԤT�褧�W���H�A��
�_����O�٥��ӷl�@�b�A�믫���M�����A�b�o������O�v�޳����j�U�A
���\�h���H�h�b�������A���ɤ]���\�h����Өӽm�Z���Z�N�a�A�o�̪�
�|�P�D�`���m�A�b�Q�V���~�~���@������������o�@���M����Z����
�a�C
LONG
	);
	set("exits", ([
  "west" : __DIR__"hippodrome.c",
]));

        set("no_die", 1);
	set("no_clean_up", 0);
	set("outdoors","land");
	set("light",1);
	setup();
}

void init()
{
	add_action("help","help");
	add_action("do_fight","fight");
	add_action("do_another","kill");
	add_action("do_another","quit");
}

int do_another()
{
	write("�藍�_, �o�̤��వ���ʧ@�I\n");
	return 1;
}

int do_fight(string arg)
{
	object obj, old_target,me;
	me = this_player();

	if( me->is_ghost() )
		return notify_fail("�A�{�b�٬O����a\n");
	if( !wizardp(me) && environment(me)->query("no_fight") )
		return notify_fail("�o�̸T��԰��C\n");
	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("�A�Q�����֡S\n");
	if( !obj->is_character() )
		return notify_fail("�ݲM���@�I�M���ä��O�ͪ��C\n");
	if( obj->is_fighting(me) )
		return notify_fail("�[�o�T�[�o�T�[�o�T\n");
	if( !living(obj) )
		return notify_fail(obj->name() + "�w�g�L�k�԰��F�C\n"); 
        if( obj->is_ghost() )
		return notify_fail("�o�ӤH�O����õL�k�԰��C\n");
	if( obj==me )
		return notify_fail("�A��������ۤv�C\n");
	if( userp(me) && !userp(obj) && obj->query_temp("pending/fight")!=me )
		return notify_fail("�A�u��䪱�a��ժZ���C\n");

	if( userp(obj) && (object)obj->query_temp("pending/fight")!=me )
	{
		message_vision("\n$N���$n���D�R" 
			+ RANK_D->query_self(me) 
			+ me->name() + "�M���"
			+ RANK_D->query_respect(obj) + "�����ۡT\n\n", me, obj);
		if( objectp(old_target = me->query_temp("pending/fight")) )
			tell_object(old_target, YEL + me->name() + "�����F�M�A��ժ����Y�C\n" NOR);
		me->set_temp("pending/fight", obj);
		tell_object(obj, YEL "�p�G�A�@�N�M���i���աM�ЧA�]��" + me->name() + "("+(string)me->query("id")+")"+ "�U�@�� fight ���O�C\n" NOR);
		write(YEL "�ѩ���O�Ѫ��a����H���M�A���������P�N�~��i���աC\n" NOR);
		return 1;
	}

	if( obj->query("can_speak") )
	{
		message_vision("\n$N���$n���D�R" 
			+ RANK_D->query_self(me) 
			+ me->name() + "�M���"
			+ RANK_D->query_respect(obj) + "�����ۡT\n\n", me, obj);
                notify_fail("�ݰ_��" + obj->name() + "�ä��Q��A���q�C\n");

		if( !userp(obj) && !obj->accept_fight(me) ) return 0;

		me->fight_ob(obj);
		obj->fight_ob(me);
	}
	else
	{
		message_vision("\n$N�j�ܤ@�n�M�}�l��$n�o�ʧ����T\n\n", me, obj);
		me->fight_ob(obj);
		obj->fight_ob(me);
	}

	return 1;
}

int help(string arg)
{
	if( arg!="fight" )return 0;
	else write(@HELP
���O�榡 : fight <�H���W��>
 
�o�ӫ��O���A�V�@�ӤH���u�Q�Сv�Ϊ̬O�u���R�Z���v�M�o�اΦ����԰��º�O
�I�쬰��M�]���u�|������O�M���|�u�����ˡM���O�ä��O�Ҧ���  NPC �����w
���[�M�]�����\�h���p�A����Z�n�D�|�Q�ڵ��C

HELP
	);
	return 1;
}
