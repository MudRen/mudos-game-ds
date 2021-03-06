// Room: /u/s/suez/grave/path_3.c

inherit ROOM;

void create()
{
	set("short", "斌山小道");
	set("long", @LONG
涼風襲襲，蟬鳴鳥叫不絕於耳，山道雖然曲折，但兩旁的山景清麗，
讓人幾乎忘記山道之難行。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"path_4",
  "eastup" : __DIR__"path_2",
]));
        set("outdoors", "land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
