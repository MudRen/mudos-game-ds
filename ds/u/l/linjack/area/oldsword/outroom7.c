#include <room.h>
inherit ROOM;
void create()
{
 set("short","小吊橋上");
 set("long",@LONG
這條吊橋寬僅兩尺, 十分不穩固, 橋繩和木板已經頗為
老舊的了, 如果在這上面做太大的動作恐怕橋會支撐不住.
LONG
    );
 set("exits",([ "west":__DIR__"outroom4",
                "east":__DIR__"outroom8",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}