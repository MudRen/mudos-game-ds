#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","西副師部");
set("long",@LONG
這裡是位於主海政部西邊的西副師部, 這裡與東副師部不
同的是....這裡沒有人! 這種終年忙得不可開交的單位, 居然
最重要的海政司西副師沒來....?!
LONG
    );
 set("exits",([ "east":__DIR__"seacoun11",
]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
