// Room: /u/a/alickyuen/area/dr24.c

inherit ROOM;

void create()
{
	set("short", "ST�CLivesaving�IDoor");
	set("long", @LONG
�o�ثK�O�o����|����g�ǡA�A�o�{��g�Ǫ��u�@�O�O�����G�ۡA�i
�Q�Ӥ����ܦh�H�]�N�~�J�|�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dr23",
]));
set("objects", ([
__DIR__"npc/wnurse" : 1,
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
