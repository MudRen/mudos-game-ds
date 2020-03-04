#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",CYN"霧峰"NOR);
 set("long",@LONG
傳說霧峰在每年秋冬交接之際，微帶褐色的霧氣就有如
潮水自霧峰的山谷中翻騰而出，在霧峰上形成一片嚇人的霧
海，而即使不是那個時節，霧峰本就多霧，在山上望不出一
尺是很常見的事.
LONG
    );
 set("exits",([  "southdown":__DIR__"ten49",
                 "north":__DIR__"ten51",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

