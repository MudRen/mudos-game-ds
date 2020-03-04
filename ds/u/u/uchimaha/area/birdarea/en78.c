#include <room.h>
inherit ROOM;
void create()
{
 set("short","東北澤林");
 set("long",@LONG
你往東走了過來, 來到了草叢裡, 有一個人的石像豎
立在石台上, 石台四周有刻著許多不知名的記號, 看樣子
是上古時期所遺留下來的, 這條路往東延伸至此.
LONG
    );
 
 set("exits",(["west":__DIR__"en76",
              ]));
 set("objects",([__DIR__"npc/statue" : 1,
     ]));
 set("outdoors","land");
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
        if (arg != "眼睛") return 0;
        
        message_vision("只見$N往石像的眼睛一推，頓時$N的身影消失不見了。\n" ,me);
        me->move(__DIR__"en79.c");
        tell_room(environment(me),me->query("name")+"突然從上方掉了下來。n",me);
        return 1;
}                 
