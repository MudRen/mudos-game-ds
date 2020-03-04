#include <room.h>
inherit ROOM;
void create()
{
 set("short","東北澤林﹝泥沼區﹞");
 set("long",@LONG
你來到東北澤林的森林泥沼區, 這裡有些白骨散落
在地上, 應該是誤闖這兒而走不出去的路人, 最後死在
這兒, 你最好趕快走, 不要逗留.

LONG
    );
 
 set("exits",(["southwest":__DIR__"en67",
               "southeast":__DIR__"en69",
               ]));
 set("objects",([__DIR__"npc/flower" : 4,
               ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
