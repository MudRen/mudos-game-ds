// Room: /u/k/king/area/r35.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[2;37;0m�C�P�L");
	set("long", @LONG
�o�̬O����̭����a��A���������ݤ���@�B�I���F��A���p���ٽ�
����Y�A�h�체�\���֬y�X�ӤF�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"44",
  "east" : __DIR__"r32",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
