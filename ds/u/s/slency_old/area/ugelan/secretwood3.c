// Room: /u/s/slency/area/ugelan/secretwood3.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"secretwood2",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");
	setup();
	replace_program(ROOM);
}
