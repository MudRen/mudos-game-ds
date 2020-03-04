// Room: /u/a/alickyuen/area/dr32.c

inherit ROOM;

void create()
{
	set("short", "ST。Hospital＠Workroom");
	set("long", @LONG
這間就是院長室了，這裡的佈置是你前所未見的那麼美的，看上去全
都是一些貴價貨品，就知道這個院長身家之豐厚了……他自你進來之後，
就一直一直望著你，你覺得自己好像身處虎穴的馴鹿……
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"dr29",
]));
set("objects", ([
__DIR__"npc/leader.c" : 1,
]));
	set("world", "future");
set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
