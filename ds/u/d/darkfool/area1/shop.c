// Room: /u/d/darkfool/area1/shop.c

inherit ROOM;

void create()
{
	set("short", "�ө�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"4",
]));

	setup();
	replace_program(ROOM);
}
