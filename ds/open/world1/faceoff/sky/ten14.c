#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","小藥店-內室");
 set("long",@LONG
一走進內室，原先的霉味早已被濃郁的藥味及陳年的書
味給取代了，在堆積如山的書堆後是一個年不過二旬的少年
人，作郎中打扮，看來就是這間藥店的主人了.
LONG
    );
 set("exits",([   "out":__DIR__"ten13",
    ]));
 set("objects", ([__DIR__"npc/doctor" : 1,
    ]));

set("no_clean_up",0);
set("light",1);
 setup();
}


