#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","庫房");

 set("long",@LONG
這裡是山寨中土匪拿來收藏搶到的財物的地方, 雖然外面
守備相當嚴密, 但是裡面倒是沒有什麼守備, 你看了一看, 只
見裡面有一個標示著 防具架 的架子, 看來這裡是土匪的防具
房.
LONG
    );
 set("exits",([ "out":__DIR__"ten18",
    ]));
 set("item_desc",([
        "防具架":"你也許可以從裡面搜出一些防具!\n",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}

void init()
{
        add_action("do_search","search");
}
int k=1;
int do_search(string arg)
{
      object me,p;
      me=this_player();
      if (arg != "防具架") return 0;
      message_vision("$N仔細的搜了搜一防具架....\n"  ,me);
if(k != 0){
           message_vision(HIY"$N搜出一件皮甲!\n"NOR ,me);
           k = 0;
        p=new(__DIR__"npc/eq/fur_armor.c");
        p->move(this_player());
        } else
        {
                message_vision("但是什麼也沒有....\n",me);
        }                               
        return 1;
}