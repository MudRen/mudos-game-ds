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
  "紙箱" : "一堆廢棄的紙箱，似乎藏著些什麼，也許\你可以翻翻看。\n",
"月台" : "你看見月台底彷彿有些黑影略過，你心想想跳下去看看。\n",
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
add_action("do_search","search");
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
int do_search(string arg)
{
        object me,to;
        me = this_player();
        to = new(__DIR__"obj/key.c");
        if( !arg ) return 0;
        if( arg!="紙箱" ) return 0;
if( query_temp("getclip") )
{
    return 0;
}
        message_vision("$N從紙箱�娷膜F翻，找到了一把鑰匙。\n",me);
        to->move(me);
        set_temp("getclip",1);
	set("item_desc", ([ /* sizeof() == 1 */
"月台" : "你看見月台底彷彿有些黑影略過，你心想想跳下去看看。\n",
]));
        return 1;
}
void reset()
{
        delete_temp("getclip");
	set("item_desc", ([ /* sizeof() == 1 */
  "紙箱" : "一堆廢棄的紙箱，似乎藏著些什麼，也許\你可以翻翻看。\n",
"月台" : "你看見月台底彷彿有些黑影略過，你心想想跳下去看看。\n",
]));
}

