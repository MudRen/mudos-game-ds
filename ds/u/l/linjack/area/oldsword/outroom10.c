#include <room.h>
inherit ROOM;
void create()
{
 set("short","草坪上");
 set("long",@LONG
這邊的南側下去就是山坡了, 蠻陡峭的, 使你無法往下行走.
這邊有一些小動物在這裡活動, 這邊風滿大的, 在這裡待太久是
會感冒的喔. 有一個身穿藍衣的人在這邊吟詩.
LONG
    );
 set("exits",([ "north":__DIR__"outroom8",
                 "east":__DIR__"outroom11",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
