// Room55.c
#include <path.h>
inherit ROOM;

void create()
{
	set("short","�Ѧa�|�P�{");
	set("long", @LONG
�A�Ө�@�P�{���U�A���W��h�A��ı�o�o�y�P�{�������C���O��
��w����^�۫ئ��A�Ӧb�ۤW����������@�Ǥ�r�C�b�P�{�������A
�a���F�@�����B�A�g�ۡu�Ѧa�|�v�T�Ӥj�r�A�঳�p����աA���O��
�U�D�W�����|�i�Ѧa�|�j�C���_�i�H��F�Ѧa�|���x�C

LONG
	);
	set("exits", ([
		"north": __DIR__"room45",
		"south": ACME_PAST+"area/pool",
	]));
	set("light",1);
	set("no_kill",1);
set("no_goto",1);
	setup();
	set("stroom",1);
}

