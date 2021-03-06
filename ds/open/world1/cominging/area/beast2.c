#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
        set("short", "步靈城東大街中");
        set("long",@LONG
你站在一條短小的街道上，到了這裡似乎就是路的終點，在東邊有
許多老舊的房屋，據說是從前某個拯救全城的英雄所葬之地，因此頗為
人們尊敬。
LONG
        );
        set("exits", ([
            "west" : __DIR__"beast1.c",
            "east" : __DIR__"beast3.c",
            "north" : "open/world1/ksj/thief/room1.c",
           ]));

        set("no_clean_up", 0);
        set("outdoors","land");
        set("objects",([
            __DIR__"npc/dove":4,
           ]) );
        create_door("north","鐵門","south",DOOR_CLOSED);
        setup();
}
