#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"天梟後院"NOR);

 set("long",@LONG
這裡是天梟位於隱士樓後方的後院, 你發現牆上掛滿了練
習天嘯匕法用的沙包, 以及用來練習輕功的石樁, 顯然這裡是
天梟弟子的練習場地, 你最好遠離這裡, 以免被突如其來的匕
首戳中, 畢竟匕首是不長眼睛的....
LONG
    );
 set("exits",([ "northeast":__DIR__"eastroad5",
                 "northwest":__DIR__"eastroad6",
                    "south":__DIR__"eastroad3",
    ]));
set("objects", ([__DIR__"npc/bird_apprentice" : 3,
    ]));

set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}
