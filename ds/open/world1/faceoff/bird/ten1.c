#include <room.h>
inherit ROOM;
void create()
{
 set("short","山壁旁");

 set("long",@LONG
你身旁就是通向山口的峭壁, 往北則通向十萬大山中次高
的滅骨峰, 你發現你的四周都是一些陡峭的岩石, 唯一的出路
似乎只有往北走了.
LONG
    );
 set("exits",([ "north":__DIR__"ten2",
		"down":__DIR__"ten_mountain4",
    ]));

 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}
