// 綠洲

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "回疆綠洲" NOR);
        set("long", @LONG
在戈壁的盡頭出現了一個綠洲。這裡有口水井，可是已經幹涸了。
LONG);
        set("valid_startroom", 1);

        set("objects", ([
			__DIR__"obj/hamigua" : 2
        ]));
 
        set("exits", ([
              "northwest" : __DIR__"gebi1",
              "southeast" : __DIR__"gebi2",
              "southwest" : __DIR__"gebi3",
              "northeast" : __DIR__"gebi4",
        ]));

        set("outdoors", "land");
        setup(); 

}
