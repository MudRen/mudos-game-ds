// Room: /u/s/sevil/1f/15.c

inherit ROOM;

void create()
{
	set("short", "�A�ȥx");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"10.c",
  "north" : __DIR__"20.c",
  "east" : __DIR__"14.c",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/miss-serve.c" : 2,
]));
    set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
