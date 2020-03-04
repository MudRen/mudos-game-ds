// Room: /u/s/superbug/workroom.c

inherit ROOM;

void create()
{
	set("short", "大蟲之家");
	set("long", @LONG
這是大蟲的工作室，滿地的蟲蟲助手正忙碌的將資料拿給大
蟲，只看見大蟲努力的工作著，原來在他身後有著一張奇(tmr)
的照片正盯著他，你不禁為大蟲擔心著他的未來...
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "train" : __DIR__"train/1.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
 call_other("/obj/board/superbug_b", "???");
}
