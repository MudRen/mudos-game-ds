#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIG"石板路"NOR);

 set("long",@LONG
至少目前這條路還頗為寬敞, 你左右都是十萬大山的山壁, 
你似乎已經踏進了十萬大山千萬條壑谷之一, 尤其令你驚訝的
是, 東方的路徑似乎比這裡又窄了許多, 你心中不知道到底要
不要走下去...
LONG
    );
set("exits",([ "east":__DIR__"ten_mountain6", 
            "west":__DIR__"ten_mountain4", 
    ]));
set("outdoors","land");
set("no_clean_up",0);
 setup();
 replace_program(ROOM);
}
