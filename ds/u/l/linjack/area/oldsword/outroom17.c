#include <room.h>
inherit ROOM;
void create()
{
 set("short","山壁下方");
 set("long",@LONG
這邊就是一處山壁的下方, 你往上看, 整個山壁非常
非常的直聳, 這麼短的距離使你無法看清楚整個山壁的面
貌. 不過有條很粗的藤蔓掛在這, 應該可以幫助你爬上去,
但是千萬得小心才行.
LONG
    );
 set("exits",([ "south":__DIR__"outroom16",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
