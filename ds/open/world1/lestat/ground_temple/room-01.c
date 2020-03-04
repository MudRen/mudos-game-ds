#include <ansi.h>
inherit ROOM;

void create()
{
        set( "short", "洞穴通道") ;
        set( "long", @LONG
走了好久，往下的通道依然不見盡頭，你回頭一望，上方的出路
也只剩一個小光點了，在這冗長的通道中，你唯一的發現是越往下走
，整個洞穴的人造痕跡越明顯。
LONG
);
        set("exits", ([ /* sizeof() == 2 */
                  "down" : __DIR__"room-02",
                  "up" : __DIR__"room-46",
        ]));
        set("light",0);
        set("no_recall","有一股怪異的磁場力量使得你無法傳送。");
        set("no_clean_up", 0);
        setup();
}

