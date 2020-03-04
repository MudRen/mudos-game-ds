inherit ROOM;

void create()
{
	set("short", "長道");
	set("long", @LONG
這裡已是走道的末端，在你的面前是一個似乎是用檜木所做的大門
，大門上畫著兩個傳奇人物，似乎用來避邪用的，不過好像眼神有些不
對勁。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yidoor",
  "south" : __DIR__"way2",
]));
	set("no_clean_up", 0);
        set("light",1);

	setup();
	replace_program(ROOM);
}
