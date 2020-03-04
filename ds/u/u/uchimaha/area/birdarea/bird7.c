#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"絕世峭壁"NOR);

 set("long",@LONG
你終於到達峭壁之上了, 你看了看四周, 並不是你
想像中的那樣草木茂盛, 反而有點荒涼, 就在你失望之
際, 你聽到在東邊有人練武的聲音, 你思考到底會是誰
呢?  

LONG
    );
 
 set("exits",(["east":__DIR__"bird8",
               "down":__DIR__"bird6",
     ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           
