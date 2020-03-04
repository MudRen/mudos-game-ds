// Room: /u/s/superbug/train/r-1.c
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "鐵路");
	set("long", @LONG
你站在月台前的鐵路上，生鏽的鐵軌讓你懷疑有多久沒有火車在這通
行了，往前看去是一片黑暗，彷彿有怪物要從其中衝出將你吞蝕了一樣，
也許你該考慮是否前進或爬上月台。
LONG
    );
	set("item_desc", ([ /* sizeof() == 1 */
  "月台" : "讓旅客等待火車的地方，看起來似乎可以爬上月台。",
]));
	set("world", "future");
	set("light", 1);
    set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"r-2.c",
]));
	set("no_clean_up", 0);

	setup();
}
void init()
{
        add_action("do_climb","climb");
}
int do_climb(string arg)
{
        object me;
        me=this_player();
        if (arg != "月台") return 0;
        message_vision("只見$N手腳並用，笨手笨腳的爬上了月台。\n" ,me);
        me->move(__DIR__"3.c");
          tell_room(environment(me),me->query("name")+"好不容易爬上了月台。\n",me);
        return 1;
}
