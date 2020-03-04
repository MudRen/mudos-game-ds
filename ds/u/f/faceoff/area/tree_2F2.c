#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","樹枝");

 set("long",@LONG
這裡是位於參天古木上的眾多樹枝之一, 而這些樹枝都大
到足以承受你的重量, 所以你可以行走在這上面而不用擔心會
摔到下面, 你越是向前走向這個大自然或造物主所創造的綠色
迷宮, 越是感到你迷路的可能.....  
LONG
    );
 set("exits",([ "west":__DIR__"tree_2F3",
"east":__DIR__"tree_2F2",
"north":__DIR__"tree_2F2",
"south":__DIR__"tree_2F2",
    ]));

set("no_clean_up", 0);
set("no_map",1);
set("no_map",1);
 setup();
 replace_program(ROOM);
}
