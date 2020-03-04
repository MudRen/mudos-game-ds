#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","廣場");

 set("long",@LONG
你步至於此, 立刻感到一股殺氣撲面而來, 使你不寒而慄, 但
你還是極於感謝這片草地使你見到你渴望見到的陽光, 你仔細一
看, 發現四周草地都有原木桿過的痕跡, 使的草的生長方向一致, 
你心裡一寒, 莫非這裡是天梟護木使的集會地!?
LONG
    );
 set("exits",([ "south":__DIR__"tree4",
                 "north":__DIR__"woodvillage1",
    ]));
set("objects", ([__DIR__"npc/woodguard" : 2,
    ]));

 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}