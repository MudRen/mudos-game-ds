// Room: /u/a/alickyuen/area/dr15.c

inherit ROOM;

void create()
{
	set("short", "ST。Hospital＠Corridor");
	set("long", @LONG
這裡人多到差點你也走不過來，每一個人也拿著很多東西準備前往南
邊的病房去探望他們的親友，原來現在剛好是探病時間。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dr16",
  "north" : __DIR__"dr12",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
