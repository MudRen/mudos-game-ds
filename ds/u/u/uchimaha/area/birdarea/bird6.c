#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"絕世峭壁"NOR);

 set("long",@LONG
你又爬了好一段時間, 你頭上的汗水已經如下雨般
的流下, 你抬起頭來往上望了望, 終於看到頂了!!
你心中不由的高興萬分, 因為你的努力終於有了代
價, 於是你加快腳步, 往上爬去。

LONG
    );
 
 set("exits",(["up":__DIR__"bird7",
               "down":__DIR__"bird5",
     ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           
