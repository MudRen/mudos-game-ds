#include <room.h>
inherit ROOM;
void create()
{
 set("short","小島");
 set("long",@LONG 
你來到泥沼中心的小島上, 四周一片寧靜, 沒有半點聲響, 
沒有蟲鳴鳥叫, 在你的身旁有一位礦石專家, 正努力的挖礦石, 
他似乎沒看到你, 如果你想回去, 可以試著再衝一次.
LONG);
 
 set("objects",([__DIR__"npc/expert" : 1,
               ]));
 set("outdoors","land");
 set("no_clean_up", 0);
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
        
        message_vision("只見$N身型閃動，已經衝到對岸去了。\n" ,me);
        me->move(__DIR__"en72.c");
        tell_room(environment(me),me->query("name")+"突然出現在這。\nn",me);
        return 1;
}                  

