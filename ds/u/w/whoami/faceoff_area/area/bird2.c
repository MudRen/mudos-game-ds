#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"天梟大院"NOR);

 set("long",@LONG 
你一走進門內, 先前的破敗氣氛立刻去了大半, 這一個大院
想來必定是所有天梟弟子聽訓, 宣傳大事的地方, 因為長期的重
量, 你腳底下的青石磚以經有了龜裂, 可見天梟雖然沒落, 但在
江湖上的影響力還是相當大的, 從你站的位置向北可以看到天梟
的大廳, 東西則各有一個分堂.
LONG);
 set("exits",([ "north":__DIR__"bird5",
                "east":__DIR__"bird4",
                "west":__DIR__"bird3",
                "out":__DIR__"bird1",
    ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}

