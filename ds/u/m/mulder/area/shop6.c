// Room: /u/m/mulder/area/shop6.c

inherit ROOM;

void create()
{
	set("short", "�s���o�� - �p��");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"road8",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
