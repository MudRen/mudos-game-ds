#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"絕世峭壁"NOR);

 set("long",@LONG
你好不容易在峭壁上找到一處稍微凸出的岩石, 於
是你決定在此稍作休息, 你環顧了一下四周, 除了岩石
還是岩石, 你不禁思考這峭壁之上到底有什麼東西, 你
又往下望了望, 發現你已經與地面有好一段距離了, 你
心中想著還要繼續往上爬嗎?

LONG
    );
 
 set("exits",(["up":__DIR__"bird3",
               "down":__DIR__"bird1",
     ]));
 set("no_clean_up", 0);
 set("limit_dodge",15);
 setup();
 replace_program(ROOM);
}           
