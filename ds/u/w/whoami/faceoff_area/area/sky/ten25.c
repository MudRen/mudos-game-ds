#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",CYN"龍井棧道"NOR);
 set("long",@LONG
從這裡再往北去, 就是號稱天下第一險的龍脊峰了, 古
時築龍井棧道時, 就屬這一段死傷最為慘重, 所以當時俗話
說《 難不難龍脊峰, 過不過橫天橋 》就是這一段棧道歷史
的最佳寫照了.
LONG
    );
 set("exits",([  "north":__DIR__"ten26",
                 "southeast":__DIR__"ten24",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

