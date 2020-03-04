// Room: /u/a/alickyuen/area/dr1.c

inherit ROOM;

void create()
{
	set("short", "ST。Hospital＠Door");
	set("long", @LONG
這�堳K是SAINT醫院的正門，你看見有不少救護車在出入，而醫務人員
又不斷的把傷者抬進醫院，實在非常忙碌。看來在某處發生了一場嚴重的災
禍。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dr2",
  "east" : __DIR__"rd2",
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
