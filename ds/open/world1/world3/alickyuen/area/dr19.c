// Room: /u/a/alickyuen/area/dr19.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ST。Hospital＠Corridor");
	set("long", @LONG
走到走廊的盡頭，你發現有一道非常雅觀的房門在你面前，在看清楚
點，原來這是頭等病房的所在地，有錢人家才有錢租住，你看到這門口寫
著：「閒雜人等，請勿來進。」
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dr18",
"east" : __DIR__"dr20",
]));
        set("item_desc", ([ /* sizeof() == 1 */
  "門" : "這是一道會自動開的門。\n",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
}

int valid_leave(object me, string dir)
{
        if( dir=="east" ) tell_object(me,"當你正想走去開那扇門時，門突然自動打開了，原來是一扇《自動門》。\n");
        return ::valid_leave(me, dir);
}