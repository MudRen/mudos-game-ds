#include <room.h>
inherit ROOM;
void create()
{
 set("short","草坪上");
 set("long",@LONG
這邊的東南兩側下去就是山坡了, 滿陡峭的, 使你無法往
下行走. 這邊有一些小動物在這裡活動, 這邊風滿大的, 在這
裡待太久是會感冒的喔.
LONG
    );
 set("exits",([ "north":__DIR__"outroom9",
                "west":__DIR__"outroom10",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}