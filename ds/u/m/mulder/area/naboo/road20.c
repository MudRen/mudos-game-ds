// Room: /u/s/sonicct/area/road20.c

inherit ROOM;

void create()
{
	set("short", "Naboo����D");
	set("long", @LONG
�o�̤��O�g�`���~���q���A�]���b�F�_���t�Ѹg�`���@�Ǭy�]�ΰ��@
�ǫD�k���ʡA�ҥH���O�g�`���@���쨺�̡C
LONG	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"road2",
 "northeast" :__DIR__"road19",
]));
	set("outdoors","road");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
