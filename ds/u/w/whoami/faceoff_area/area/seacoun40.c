#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"玲瓏工坊"NOR);
set("long",@LONG
這裡是在無砂一帶頗有名的工坊, 對於工坊的主人, 步六弧, 
也有各種傳說, 有人說他是從遼霖來的工匠, 但他自己總說自己
是匈奴人, 不過不管如何, 他的手藝的確相當巧妙!.
LONG
    );
 set("exits",([ "west":__DIR__"seacoun24",
]));
 set("objects", ([__DIR__"npc/bu" : 1,
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}            