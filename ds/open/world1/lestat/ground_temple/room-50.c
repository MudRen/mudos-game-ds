#include <ansi.h>
inherit ROOM;

void create()
{
        set( "short", "廢棄礦坑") ;
        set( "long", @LONG
散落一地的工具，丟的到處都是垃圾，這裡似乎是礦坑工人們休
息的地方，有一個老礦工正坐在旁邊喃喃自語，或許你可以從他口中
聽得一些重要的消息。
LONG
);
        set("exits", ([ /* sizeof() == 2 */
                  "north" : __DIR__"room-48",
                  "west" : __DIR__"room-49",
        ]));
        set("objects",([
                   __DIR__"../npc/old_worker" : 1,
                 ]) );
        set("light",0);
        set("item_desc", ([ /* sizeof() == 1 */
        "工具" : "工具的後面似乎藏著什麼東西，你可以將東西移開(move)看看。\n",
        ]) );
        set("no_clean_up", 0);
        setup();
}

void init()
{
      add_action("do_move","move");
}

int do_move(string arg)
{
       object me;
       me=this_player();
       if(arg != "工具")
       return 0;
       else {
       	if(this_object()->query("havemove")) 
       	{
       		return notify_fail("這些工具已經被移到牆角了。\n");
       	}
        
        message_vision("$N將工具移到一旁，山壁上的通道因此顯露出來。\n",me);
        set("exits", ([
             "north" : __DIR__"room-48",
             "west" : __DIR__"room-49",
             "south" : __DIR__"room-51",
         ]));
        set("item_desc", ([ /* sizeof() == 1 */
        "工具" : "工具被人凌亂的堆在牆角。\n",
        ]) );
        this_object()->set("havemove",1);
         return 1;
        }
}

void reset()
{
	set("item_desc", ([ /* sizeof() == 1 */
        "工具" : "工具的後面似乎藏著什麼東西，你可以將東西移開(move)看看。\n",
        ]) );
	set("exits", ([ /* sizeof() == 2 */
                  "north" : __DIR__"room-48",
                  "west" : __DIR__"room-49",
        ]));
        this_object()->delete("havemove");
	::reset();
}
