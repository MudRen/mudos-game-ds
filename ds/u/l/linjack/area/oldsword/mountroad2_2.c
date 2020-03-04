#include <room.h>
inherit ROOM;
void create()
{
 set("short","山路上");
 set("long",@LONG
這條山路也是可以通到向雲堂的一條山路, 這邊的山路都
很錯綜複雜, 你一不小心就會迷了路了. 你可以繼續上山, 或
者是往西北走到達山腰的平台上.
LONG
    );
 set("exits",([ "northwest":__DIR__"mountroad2_3",
                "east":__DIR__"mountroad2_1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}