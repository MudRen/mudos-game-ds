// Room: /u/a/alickyuen/area/enter.c

inherit ROOM;

void create()
{
	set("short", "[1;36mST。Door＠CyberZoo[2;37;0m");
	set("long", @LONG
這裡是Saint裡最有名的機械動物園，這裡的動物都是由Saint的科學
家研究出來的，但是他們都可以生育的。因為所有的動物都差不多絕種了
，所以未來世界的寵物都是機械化的。你可以到入場處買票入去看動物。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"door.c",
  "enter" : __DIR__"enter2.c",
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
