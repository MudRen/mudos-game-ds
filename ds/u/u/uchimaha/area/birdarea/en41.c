#include <room.h>
inherit ROOM;
void create()
{
 set("short","東北澤林");

 set("long",@LONG
這裡的樹木比較稀疏, 你四周看看, 景物似乎都沒有
變, 不過有一叢草叢有些可疑, 似乎後面有些東西, 你的
好奇心驅使你去看一看.

LONG
    );
 set("item_desc",([
        "草叢":"這草叢好像可以穿(pass)過去的樣子。\n",
     ]));
 set("exits",(["southeast":__DIR__"en40",
               "northwest":__DIR__"en46",
     ]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
}
void init()
{
        add_action("do_pass","pass");
}

int do_pass(string arg)
{
        object me;
        me=this_player();
        if (arg != "草叢") return 0;
        
        message_vision("只見$N身型慢慢的消失在草叢中。\n" ,me);
        me->move(__DIR__"en42.c");
        tell_room(environment(me),me->query("name")+"從草叢的另一端穿了過來。n",me);
        return 1;
}          
