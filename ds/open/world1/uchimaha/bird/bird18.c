#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","走廊");

 set("long",@LONG
這是一條陰暗的走廊, 說它陰暗倒不如說它有些詭
異, 你看了看四周, 你發現這裡的人很喜歡石頭, 不儘
天梟像是用石頭做的, 連牆壁地板也是石頭做的, 往東
通往內堂, 往西則是大堂。

LONG
    );
 
 set("exits",(["east":__DIR__"bird19",
               "west":__DIR__"bird15",
    ]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}           

