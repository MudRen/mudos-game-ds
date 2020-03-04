#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","森林");

 set("long",@LONG 
這裡除了一成不變的樹林外, 唯一有生氣的只有你腳旁的小
動物, 你不禁疑惑這個森林到底出了什麼事? 為什麼有些殘木看
起來似乎被火燒過呢? 你腳下的道路雖然寬大, 但是好像已經很
久沒人踩過了.....
LONG
    );
 set("exits",([ "north":__DIR__"tree4",
                    "east":__DIR__"tree5",
                    "south":__DIR__"tree2",
    ]));
 set("no_clean_up",0);
 set("outdoors","forest");
 setup();
 replace_program(ROOM);
}
