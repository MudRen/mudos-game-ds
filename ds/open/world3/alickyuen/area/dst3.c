// updated 26/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST。Road＠South[2;37;0m");
	set("long", @LONG
一條連結Centre和Ship的街道，平常的人經過這條街道，都不會留意
到這條街道的特色何在。但當你在這裡留心一看，就會發現到一些平時你
注意不到而又令你驚訝的事．．．．．．
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dst2.c",
  "north" : __DIR__"dmid.c",
]));
   set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
