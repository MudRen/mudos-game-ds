// Room: /u/a/alickyuen/area/dr29.c

inherit ROOM;

void create()
{
	set("short", "ST。Hospital＠Corridor");
	set("long", @LONG
這裡是走廊的盡頭，而裡面就是醫院最高權力者－－院長的房間，見
習醫生都要進去受院長的測試……而所有病人出院都要有院長的批准，不
過聽聞他真的可怕得很，員工都在討論著他的一舉一動。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"dr28",
  "enter" : __DIR__"dr32",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
