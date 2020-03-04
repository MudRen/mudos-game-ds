#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"絕世峭壁"NOR);

 set("long",@LONG
又過了不少時間, 你覺得這個峭壁高的驚人, 不是
平常人所能爬上來的, 你的好奇心又加深了一分, 到底
在這峭壁之上有什麼東西, 但是你的恐懼心也加深了一
分, 那個長嘯的人到底是誰呢?

LONG
    );
 
 set("exits",(["up":__DIR__"bird4",
               "down":__DIR__"bird2",
     ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           
