// Room: /u/s/superbug/train/1.c
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "月台");
	set("long", @LONG
這裡是一個讓火車停靠的月台，寬廣的月台卻只有稀稀疏疏的幾個旅
客，由於缺乏維修，頭上的燈光一明一滅的，令你看不清楚，在角落似乎
有幾個紙箱？標誌寫著往右走是管理處。
LONG
    );
	set("item_desc", ([ /* sizeof() == 1 */
  "紙箱" : "一堆廢棄的紙箱，似乎藏著些什麼，也許你可以翻翻看(search)。",
]));
	set("world", "future");
	set("light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"1.c",
  "east" : __DIR__"5.c",
]));
	set("no_clean_up", 0);

	setup();
}
void init()
{
        add_action("do_jump","jump");
}
int do_jump(string arg)
{
        object me;
        me=this_player();
        if (arg != "月台") return 0;
        message_vision("只見$N深吸一口氣，跳下了月台。\n" ,me);
        me->move(__DIR__"r-1.c");
          tell_room(environment(me),me->query("name")+"跌了一跤，好不容易站了起來。\n",me);
        return 1;
}
