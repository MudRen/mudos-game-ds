#include <room.h>
inherit ROOM;
void create()
{
 set("short","石室中");
 set("long",@LONG
這個石室中空蕩蕩的, 什麼也沒有.....
你發覺這邊的地板好像怪怪的.
LONG
    );
 set("exits",([ "west":__DIR__"outroom9",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}