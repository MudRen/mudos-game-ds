#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short","東北澤林");
set("long", @LONG
你往東走了過來, 來到了草叢裡, 在這裡有一個人的
石像, 從這石像看來, 這石像刻的人似乎全身都是黑的, 
你仔細一看, 發現它的眼睛有常被人推的痕跡, 這條路往
東延伸至此.

LONG
        );
        set("exits",(["west":__DIR__"en76",
                      ]));
        
        set("item_desc",([
        "石像":"一個烏漆嗎黑的石像，石像眼睛好像可以堆動的樣子(push)。\n",
         ]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}
void init()
{
        add_action("do_push","push");
}

int do_push(string arg)
{
        object me;
        me=this_player();
        if (arg != "石像眼睛") return 0;
        
        message_vision("只見$N往石像的眼睛一推，頓時$N的身影消失不見了。\n" ,me);
        me->move(__DIR__"en79.c");
        tell_room(environment(me),me->query("name")+"突然從上方掉了下來。n",me);
        return 1;
}          


