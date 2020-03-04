#include <room.h>
inherit ROOM;
void create()
{
 set("short","草坪上");
 set("long",@LONG
這個草坪有點異常的安靜, 連風聲都沒有, 只能聽到
細微的流水聲, 也沒有什麼動物在這邊出沒, 北邊樹木茂
盛, 是條幽暗的小路, 東邊有個小石室.
LONG
    );
 set("exits",([ "west":__DIR__"outroom8",
                "east":__DIR__"s_room",
               "south":__DIR__"outroom11",
               "north":__DIR__"outroom12",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}