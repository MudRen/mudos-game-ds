#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","大茅屋");
 set("long",@LONG
你現在正置身於一座大茅屋的中央，問了一路上的村人，
才知道原來這是宗族長的家，也就是上一代的長子，在封建
的民風當中，宗族長的權力相當於地方官，這也就是為什麼
數年來苗家村始終沒有設置村長的原因了.
LONG
    );
 set("exits",([   "west":__DIR__"ten18",
    ]));
set("objects", ([__DIR__"npc/meo_chung" : 1,
    ]));

set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}

