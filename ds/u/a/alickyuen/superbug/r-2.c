// Room: /u/s/superbug/train/r-2.c

inherit ROOM;

void create()
{
	set("short", "�K������");
	set("long", @LONG
�@��i�o�̡A�ϩ���i�F�t�@�ӥ@�ɤ@�ˡA���᪺���G�M���e���·t
���j�P�����A�A���T�Q�h��@�B�^���x�W�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r-3.c",
  "south" : __DIR__"r-1.c",
]));
set("objects", ([
__DIR__"npc/guard3" : 1,
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
