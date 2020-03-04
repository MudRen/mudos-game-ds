#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"破敗的石門"NOR);

 set("long",
"你望了一望門內, 發現一切都是破敗不堪的, 果然江湖上傳\n"
"言天梟沒落是真實的, 你不禁感嘆起分裂竟然能夠使一度稱霸江\n"
"湖, 傳言【"HIC"江湖幻滅似斗星, 唯有天梟霸千世"NOR"】的一個教派落得\n"
"如此下場.....\n"
);
 set("exits",([ "enter":__DIR__"bird2", 
                "west":__DIR__"ten_mountain7",
    ]));
 set("objects", ([__DIR__"npc/birdguard" : 2,
    ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}

