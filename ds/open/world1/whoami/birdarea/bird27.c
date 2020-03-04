#include <room.h>
inherit ROOM;
void create()
{
 set("short","大樹下");

 set("long",@LONG
你站在一棵擁有茂密枝葉的大樹底下, 強烈的陽光讓你睜不
開眼, 你的旁邊有一個小販, 他那裡有賣很多東西, 而且服務態
度也不錯, 你可以看看有賣什麼東西, 你的西方到天梟教的練功
場。
LONG
    );
 
 set("exits",(["west":__DIR__"bird25",
     ]));
 set("objects",([__DIR__"npc/waiter2" : 1,
     ]));
 set("no_fight", 1);
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
 replace_program(ROOM);
}           

