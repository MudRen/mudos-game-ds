// room02.c
#include <path.h>
inherit ROOM;

void create()
{
	set("short", "[1;36m���z���ܢޢѬ�s��[0m");
	set("long", @LONG
�z����......�o�̦����z���ͪ���......�p�ߧA���p����
�Q�L�̫�˳�......�H�H�H...�C
LONG
	);

	set("exits", ([ /* sizeof() == 7 */
		"west" : __DIR__"room01",
	]));
	set("objects", ([ /* sizeof() == 1 */
		"/u/s/shengsan/npc/liliya" : 1,
	]));
	set("light", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}