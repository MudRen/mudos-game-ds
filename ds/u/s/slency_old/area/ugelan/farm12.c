// Room: /u/s/slency/area/ugelan/farm12.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"farm11",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
