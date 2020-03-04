// Room: /u/a/alickyuen/area/dr22.c

inherit ROOM;

void create()
{
	set("short", "ST。Hospital＠Sickroom");
	set("long", @LONG
你看到一個個病人臥在病床上，有點心傷．．．．．．這裡是一般普
通的病房，不論任何人也能入住，非常閒雜。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dr17",
]));
set("objects", ([
__DIR__"npc/patient" : 1,
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
