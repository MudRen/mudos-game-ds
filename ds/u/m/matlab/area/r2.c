// Room: /u/m/matlab/area/r2.c

inherit ROOM;

void create()
{
	set("short", "�_����");
	set("long", @LONG
���D��o�ؤ��O�V�F�������F�}�ӡA�E�ݤ��U���䳺�M�@�Ҥ@��!!
�A���ؤ��T�x�_�@�Ѳ��˪��Pı....
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"r1.c",
  "west" : __DIR__"r2-2.c",
  "east" : __DIR__"r2-1.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
