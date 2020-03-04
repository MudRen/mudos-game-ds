#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","道路");
 set("long",@LONG
你經過了好幾天的路程終於到達這了. 通過了一大片就只
比沙漠好那麼一點點的拓墾區, 不禁覺得有些荒涼....往北走
去就往山區去了.
LONG
    );
 set("exits",([ "north":__DIR__"mountdown8",
                "southeast":__DIR__"field",]));
 set("no_clean_up", 0);
 setup();
}
int valid_leave(object me, string dir)
{
 if( dir=="southeast")
  write(YEL"\n你開始往那荒野走去....走回拓墾區.\n\n"NOR);
 return ::valid_leave(me, dir);
}
