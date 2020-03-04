#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"儲藏室"NOR);
        set("long", @LONG
這就是這位無名式的儲藏室，裡面擺設著許多兵器，但這些兵器外，
好像都有一層看不見的保護層，只要你一去觸摸，就會被傷害到至受傷似
。另外，前方有個櫃子，裡頭好像放置著一個兵器，但那個兵器的領域跟
其它的兵器不同，有一種讓人想去嘗試使用這個兵器的慾望。
LONG
        );
        
        
        set("outdoors", "land");
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"room13",
]));  
  set("item_desc", ([
  "鐵板" : "這裡有一個莫名其妙的鐵板，你可以拉拉看(pull)看有什麼東西。\n",
]));
   set("no_clean_up", 0);
        setup();
}     

void init()
{
        add_action("do_pull","pull");
}

int do_pull(string arg)
{
        object me;
        me=this_player();
        if(!arg || arg!="鐵板" ) return 0;
        message_vision(HIW"你 拉 開 了 鐵 板 上 的 鎖 ， 突 然 間 跌 了 下 去!! \n"NOR,me);
        me->move(__DIR__"q5-1");
          tell_room(environment(me),me->query("name")+HIW"忽然從天上跌了下來。\n"NOR,me );
return 1;
}

