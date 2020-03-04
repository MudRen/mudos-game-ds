#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit DOOR;
void create()
{
 set("short","採藥者小屋");

 set("long",@LONG 
你置身於這棟一無所有的小屋中央, 發現因為多年沒有天梟
採藥者前來, 所以這棟小屋除了一些破舊的藥鋤及一堆堆的朽木
以外, 就只剩下一只小小的睡袋了....這裡的破舊果然是不言可
知的..........
LONG
    );
 set("exits",([
     "out":__DIR__"tree7",
     ]));
 set("no_clean_up",0);
 set("light",1);
 set("item_desc",([
    "睡袋" : "一只全新還沒人用過的睡袋，看來拿走(take)也沒人會知道•\n", 
    "藥鋤" : "一個用來挖取藥材的工具•\n",                 ]));   
 set_temp("tent",1);
 setup();
 create_door("out","破爛的木門","enter",DOOR_CLOSED,"nokey");
}

void init()
{
        add_action("do_take","take");
}

int do_take(string arg)
{
        object me,tent;

        me=this_player();
        if(arg != "睡袋") return notify_fail("你要拿什麼??\n");
        if( this_object()->query_temp("tent") ){
        message_vision("$N左看右喵的，鬼鬼祟祟的拿走一個睡袋•\n",me);
        tent=new("/open/world1/wilfred/sand/npc/obj/obj11");
        tent->move(me);
        this_object()->add_temp("tent",-1); 
        call_out("rb", 300, this_object());        } else {
        tell_object(me,"看來已經有人捷足先登了喔！\n");       
        }
        return 1;       
}

void rb()
{
       this_object()->set_temp("tent",1);       
       return;
}

