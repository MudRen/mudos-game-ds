#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"東北"NOR"澤林");
 set("long",@LONG
你往北走了過來, 附近的樹木還是一樣的茂密, 但是你往更
遠的地方望去, 卻被山群的峭壁所環繞, 這條小路往東方延伸出
去.
LONG);
 set("exits",(["south":__DIR__"en75",
               "east":__DIR__"en78",
               ]));
 
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}
