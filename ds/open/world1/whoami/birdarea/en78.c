#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"東北"NOR"澤林");
 set("long",@LONG
你往東走了過來, 來到了草叢裡, 有一個人的石像豎立在石
台上, 石台四周有刻著許多不知名的記號, 看樣子是上古時期所
遺留下來的, 這條路往東延伸至此結束.
LONG);
 
 set("exits",(["west":__DIR__"en76",
              ]));
 set("objects",([__DIR__"npc/statue" : 1,
     ]));
 set("outdoors","forest");
 set("no_clean_up", 0);
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
        if (arg != "眼睛" && arg != "石像的眼" && arg != "石像的眼睛" && arg != "眼") return 0;
        
        message_vision("只見$N往"HIW+BLK"石像"NOR"的眼睛一推，頓時$N的身影消失不見了。\n" ,me);
        me->move(__DIR__"en79.c");
        tell_room(environment(me),me->query("name")+"突然從上方掉了下來。n",me);
        return 1;
}                 
