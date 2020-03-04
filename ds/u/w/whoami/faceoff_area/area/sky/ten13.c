#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","小藥店");
 set("long",@LONG
你一跨入這一間小小的茅屋，立刻聞到一陣刺鼻的霉味
，和屋內的藥香形成了強烈的對比，在你肩膀旁的台子後是
一面由樟木所刻成的匾額，上面寫著《 妙手回春 》你可以
看到在門簾後面還有一間內室.
LONG
    );
 set("exits",([   "enter":__DIR__"ten14",
               "south":__DIR__"ten12",
    ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}
