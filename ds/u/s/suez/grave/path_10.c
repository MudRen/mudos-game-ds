// Room: /u/s/suez/grave/path_10.c

inherit ROOM;

void create()
{
	set("short", "�s�s�j�D");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "in" : __DIR__"tea_shop",
  "west" : __DIR__"path_9",
]));
	set("no_clean_up", 0);
        set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
