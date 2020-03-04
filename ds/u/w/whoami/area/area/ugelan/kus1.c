#include <ansi.h>
inherit ROOM;
void create()
{
 set("short","庫司港");

 set("long",@LONG
你現在來到了庫司港的泊船處, 旁邊停著幾艘小船, 這裡
的海風大的出奇, 你假如稍微不注意就會被海風吹退兩三步, 
這裡也是出海的地方•
LONG
    );
 set("item_desc",([
     "小船":"你可以進去(enter)看看•\n",
     ]));
 set("exits",(["east":__DIR__"kus2",
       ]));
 set("outdoors","land");
 setup();
} 
void init()
{
        add_action("do_enter","enter");
}
int do_enter(string arg)
{
        object me;
        me=this_player();
        if (arg != "小船") return 0;
        
        message_vision("只見$N走進了小船。\n" ,me);
        me->move(__DIR__"boat.c");
        tell_room(environment(me),me->query("name")+"走了進來。n",me);
        return 1;
}          
int room_effect(object me)
{
          switch(random(10))
        {
         case 0:
         
                message_vision("強烈的海風往你身上吹來。\n",me);
                if(me->query_skill("dodge")< 30 || random(10)<3 )
                {
                        tell_object(me,HIC"你被海風吹得倒退了兩三步\n" NOR ); 
                        me->add_busy(1);
                }
                return 1;
        

         default:       return 1;
        }
}

