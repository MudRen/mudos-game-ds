// Room: /u/s/sonicct/area/road9.c

inherit ROOM;

void create()
{
	set("short", "Naboo����D");
	set("long", @LONG
�o�O�s���j�˪L���D���A�ѩ�o�̤������˪L�A�ҥH�A��
�@�زM�s�۵M���Pı�C����i�H�q��Naboo�s���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"gate3",
  "west" : __DIR__"road8",
]));
	set("outdoors","road");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
