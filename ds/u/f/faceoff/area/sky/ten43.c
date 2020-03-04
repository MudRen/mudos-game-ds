#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",MAG"禰影神廟"NOR);
 set("long",@LONG
一踏進神廟的大門，立刻有一股神聖不可侵犯的感覺湧
進你的心中，傳說禰影之神是創造十萬大山的三神之首，也
因此在十萬大山人民的心中留下不可磨滅的形象，所以禰影
之神是三神中最受尊崇的對象....
LONG
    );
 set("exits",([   "westdown":__DIR__"ten42",
                  "east":__DIR__"ten44",
    ]));
 set("objects", ([__DIR__"obj/lion_statue" : 2,
    ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}

