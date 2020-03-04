// Room: /d/wiz/courthouse.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "�k�|");
	set("long", @LONG
�o�̬O�ڤۤC�쪺�Ův�f�ݾ����H���k�|�M�A�@�w�O�Q�H���|�άO
�欰�ӹ������H�M�~�|�Ө�o�̡M�p�G�A�����X�f�P�x���T�Ӱ��D�M�|
�Q���W�O���M���~�W�L�T�����H�N�|�Q�B�H���D�M�n�n�^���a�C

	�^����k�O��[answer]�o�ӫ��O�A�榡��: answer <�Ʀr>


LONG
	);
	set("no_fight", 1);
	set("no_cast", 1);
	set("no_exert", 1);
	set("no_recall", 1);
	set("light", 1);
	set("objects", ([
		__DIR__"npc/judge":1 ]) );

	setup();
}

void init()
{
/*
	add_action("no_quit","quit");
	add_action("no_drop","drop");
	add_action("no_give","give");
*/
//        add_action("no_get","get");
        if( !wizardp(this_player()) && !this_player()->is_npc() )
	{
		add_action("do_action", "", 1);
		write(BEEP"");
	}
}

int no_quit(string arg)
{
	write("�A�{�b����Quit!!\n");
	return 1;
}
int no_drop(string arg)
{
	write("�A�{�b����Drop���O!!\n");
	return 1;
}
int no_give(string arg)
{
	write("�A�{�b����ϥ�Give���O!!\n");
	return 1;
}
int no_get(string arg)
{
	write("�A�{�b����ϥ�Get���O!!\n");
	return 1;
}

void test_me(object me)
{
	me->set_temp("old_startroom", me->query("startroom"));
	me->set("startroom", __FILE__);
	me->set_temp("last_location", base_name(environment(me)));
	message_vision("���M�@�}�{���n��F$N�C\n", me);
	me->move(this_object());
}

int do_action()
{
        if ( (string)query_verb() == "answer" )
        { return 0; }
        if ( (string)query_verb() == "tchat" )
        { return 0; }
        if ( (string)query_verb() == "look" )
        { return 0; }
        write("Sorry, �b�k�|�٬O�w���I�n�C"NOR""WHT"�`�N: �b�o�̯�Ϊ����O�u��:\n  tchat, answer\n"NOR);
	return 1;
}
