#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIG"山口"NOR);

 set("long",@LONG
這裡再往北走就是著名的十萬大山了, 據說天梟練武一派
便是隱居在群山當中, 暫且不提這事, 就是眼前的景色也相當
迷人, 層層山峰聳立在你的面前, 別有一番蒼涼的風味.
LONG
    );
 set("exits",([ "north":__DIR__"ten_mountain3",

    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}
