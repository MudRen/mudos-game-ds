// Room: /u/t/tmr/room/square.c

inherit ROOM;

void create()
{
	set("short", "中央廣場");
	set("long", @LONG
這裡是奇家的中央廣場﹐一株巨大的老榕樹盤根錯結地站在中央
﹐一些孩童常常爬上這株老榕嬉戲﹐榕樹下七橫八豎地放著幾張長凳供
人歇息聊天﹐
LONG
	);
	set("light", 1);
	set("current_light", 1);
	set("item_desc", ([ /* sizeof() == 1 */
  "長凳" : "十分普通常見的長凳﹐如果你累了﹐不必客氣﹐盡管做下來休息。

",
]));
	set("exits", ([ /* sizeof() == 2 */
  "out" : "/u/t/tmr/workroom",
  "enter" : __DIR__"room1",
]));
	set("no_clean_up", 0);

	setup();
        call_other("/obj/board/tmr_b", "???");

}
