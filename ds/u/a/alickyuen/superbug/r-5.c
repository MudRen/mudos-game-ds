// Room: /u/s/superbug/train/r-5.c

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
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"r-6.c",
  "south" : __DIR__"r-4.c",
  "east" : __DIR__"r-11.c",
]));
set("objects", ([
__DIR__"npc/mouse" : 1,
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
