//updated 26/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST。Building＠Enterance[2;37;0m");
	set("long", @LONG
這裡是一個通行證的申請站，到這裡可以為一些有需要的人士快捷申
請到通行證離開這個國家。但當你想申請更高級的通行證去其他星球時，
你就需要到宇宙人民入境事務處裡辦理手續，因為這裡不提供的。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"dst14",
]));
set("objects", ([
__DIR__"npc/passport.c" : 1,
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
