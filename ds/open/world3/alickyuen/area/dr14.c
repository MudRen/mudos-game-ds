// Room: /u/a/alickyuen/area/dr14.c

inherit ROOM;

void create()
{
	set("short", "ST�CHospital�IHall");
	set("long", @LONG
�o�ثK�O��|���G�ӡA�o���ݩ���E���A������_�����g���i�H��o
�������v�A���A��������d�U�@�Ӫ��n�O�B���w�E�E�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"dr13",
]));
set("objects", ([
__DIR__"npc/oldman" : 1,
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
