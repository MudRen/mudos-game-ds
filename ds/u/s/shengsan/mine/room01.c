// room01.c
#include <path.h>
inherit ROOM;

void create()
{
	set("short", "[1;36m��ͮx�|���Y[0m");
	set("long", @LONG
�o�Ө��Y�R���۰��Q����^�A���Y�~����Ǻص۪��C��B�f��B�Q��
�H���٦��@�j�����{�������C
LONG
	);

	set("exits", ([ /* sizeof() == 7 */
		"east" : __DIR__"room02",
		"west" : SHENGSAN+"workroom",
		"north": __DIR__"sendroom",
	]));
	set("objects", ([ /* sizeof() == 1 */
		"/u/s/shengsan/npc/suya" : 1,
		"/u/s/shengsan/npc/robot01" : 1,
	]));
	set("light", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
