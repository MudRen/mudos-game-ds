#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"青石廊"NOR);

 set("long",@LONG
越是往石廊內走去, 教眾, 鳥兒越少, 但身穿清一色服裝的天梟卻越
多, 越密集, 表情也越嚴肅, 看來是越靠近天梟教的重要地方了, 兩旁的
燈火有如你的好奇心一般, 燃燒的越來越旺盛.
LONG
    );
 set("exits",([ "east":__DIR__"center",
                "west":__DIR__"center2",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

