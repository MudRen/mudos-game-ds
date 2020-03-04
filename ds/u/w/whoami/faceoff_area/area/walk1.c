#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"北走道"NOR);
 set("long",@LONG
這裡是天梟的北走道, 佈置與南走道大同小異, 這條走道上
有許多行人, 人來人往的好不熱鬧! 看來再往北走就是天梟教徒
的居所了, 往南則是門廊.
LONG
    );
 set("exits",([ "north":__DIR__"walk3",
            "south":__DIR__"pill2",
]));
 set("objects", ([__DIR__"npc/prayer" : 2,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
