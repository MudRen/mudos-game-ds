// Room: /d/gumu/jianshi.c
// Last Modifyed by Winder on Jan. 14 2002

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIC"�C��"NOR);
	set("long", @LONG
�@���\���L�����۫ǡA�ܦh�ؼC������a���b�a�W�C�P�򪺤���
�Ӫ���ӥ۫ǿO���q���A�X�ӥj�ӧ̤l�����b�Ǥ��J�ӬD��ۤv�X�⪺
�L�b�C�٨���ۤ@�Ӥ��@��[�A�W�����ۨǥj�ӧ̤l���ɨ����Ϊ�
�@��C
LONG	);
	set("exits", ([
		"south" : __DIR__"mudao07",
	]));

	setup();
	replace_program(ROOM);
}

