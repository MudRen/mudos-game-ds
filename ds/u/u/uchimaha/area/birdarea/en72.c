#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","東北澤林");

 set("long",@LONG
你繼續往北走, 似乎來到東北澤林的深處了, 你望了
望四周, 只有西邊有一片泥沼, 其他都是一堆樹木, 這條
路隱約往北延伸.

LONG
    );
 set("item_desc",([
        "泥沼":"一片泥沼，在泥沼的中心有一個小島，如果你認
為你的輕功\不錯，可以試著跑過去。\n",
     ]));
 set("exits",(["south":__DIR__"en46",
               "north":__DIR__"en74",
     ]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
}
void init()
{
        add_action("do_run","run");
}

int do_run(string arg)
{
        object me;
        me=this_player();
        if (arg != "泥沼") return 0;
        
        message_vision("只見$N身型閃動，已經衝到島上去了。\n" ,me);
        me->move(__DIR__"en73.c");
        tell_room(environment(me),me->query("name")+"突然出現在這。n",me);
        return 1;
}          
