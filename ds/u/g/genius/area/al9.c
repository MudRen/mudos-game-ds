#include <ansi.h>
inherit ROOM;

void create()
{
set("short","�R�����p��");
        set("long", @LONG
al9..............�ȵL�ԭz
LONG
        );
        set("exits", ([
     "south":__DIR__"al8",
     "north":__DIR__"al10",
]));

        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
