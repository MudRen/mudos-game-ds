// Room: /u/t/tmr/area/vroad3.c
#include <path.h>

inherit ROOM;

void create()
{
	set("short", "�s���D��");
	set("long", @LONG
�A�����b�@���D���W�A���F�i��F�@���s���A�b�A�_��O�y�p�q�A�u
�����֤H�i�X�A�ݱo�X�Ӧ����q�t�����˻ῳ���C���n�����p�e�A��O��
���̭��n���@���e�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : WD_PAST+"sand/room1",
  "north" : __DIR__"fane",
  "east" : __DIR__"vroad2",
  "southwest" : __DIR__"m_river",
]));
	set("outdoors","land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
