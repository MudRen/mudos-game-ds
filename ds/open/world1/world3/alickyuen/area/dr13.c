// Room: /u/a/alickyuen/area/dr13.c

inherit ROOM;

void create()
{
	set("short", "ST。Hospital＠Corridor");
	set("long", @LONG
你拿過了籌，經過這條走廊，準備走向南面的門診部去看病，而和你
同行的病人臉色都很差，而你亦加快腳步，免得自己要等一段時間，才能
看到醫生。你亦看到不少年輕的女病人開心的由南面走過來，難道有什麼
好事？
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dr14",
  "north" : __DIR__"dr11",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
