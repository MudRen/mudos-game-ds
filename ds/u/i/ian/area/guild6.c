#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"神隼聖廊"NOR);

 set("long",@LONG
這裡是一條鋪著石磚的大石廊, 有幾隻大隼在石廊中飛來飛去, 看起
來威猛無比...
LONG
    );
 set("exits",([ "south":__DIR__"guild5",
                "north":__DIR__"center",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

