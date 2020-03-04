// mudao01.c �ӹD
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"�ӹD"NOR);
	set("long", @LONG
�o���O�j�Ӥ����ӹD�A�|�P�K���z���A�ɵ��٤W���t���O���A�A��
�j�j����X��V�C�٬O�ξ�����C�۬�X�_�Ӫ��A���X�o�ƬO�����A��
�H�q����X�@���_�ءC�O���Ӧb�C�۾��W�A�{�{�ۺѫիժ����I�C
LONG	);
	set("exits", ([
		"north" : __DIR__"mumen",
		"south" : __DIR__"qianting",
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_move", "push");
}

int do_move(string arg)
{
	object room, me = this_player();

	if( !arg || arg != "�C��" )
	{
        return notify_fail("�A�n���ʤ���H\n");
	}
	if( !query("exits/north"))
	{
        return notify_fail("���s�ۤw�g���U�F�A�A�S���F��n���ʡC\n");
	}
	if((int)me->query_str()>33)
	{
		message_vision("$N���b���s�۫e�A���x�o�O���ʭ��s�ۡA�uť�o���s�ۧs�s�s�n�A�w�w�V�U���h�A�ʦ�F�Ӫ��C\n", me);
		if( !(room = find_object(__DIR__"mumen")) )
			room = load_object(__DIR__"mumen");
		room->delete("exits/south");
		tell_room(room,"�uť�o���s�ۧs�s�s�n�A�w�w�V�U���h�A�ʦ�F�Ӫ��C\n");
	}
	else
		message_vision("$N�յ۱��F�����ۡA���ۯ������ʡA�u�o�}�F�C\n", this_player());
	return 1;
}

