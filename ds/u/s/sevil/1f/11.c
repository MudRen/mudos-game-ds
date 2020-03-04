// Room: /u/s/sevil/1f/11.c

inherit ROOM;

void create()
{
	set("short", "�ʳf���q���j��");
	set("long", @LONG
�o�̬O�ʳf���q���j���A�@��i�o�̡A�ﭱ�Ǩӡu�w����{�v���n���A;
���T���A�P��@�}���a�A���̭����h�A���ت����C�M���G�����u�A���A���@
�ب��b�Ӯc���Pı�A�ϧA���T�h�óo�O�_�u�O�@���ʳf���q�C

LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"6.c",
  "west" : __DIR__"12.c",
  "north" : __DIR__"16.c",
  "east" : "/u/s/sevil/workroom.c",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/miss-door.c" : 2,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
