// Room: /u/s/superbug/train/r-3.c

inherit ROOM;

void create()
{
	set("short", "�K������");
	set("long", @LONG
�A���M�o�{�P�򳴤J�@���·t�����A���F�_�_���򪺺w���n�A�Ať��
������n���A�ϩ����i�F�·t���@�ɤ����A�A�u��u���K�y�樫�A�H�K
�b�·t���g����V�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r-4.c",
  "south" : __DIR__"r-2.c",
]));
set("objects", ([
__DIR__"npc/man" : 1,
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}