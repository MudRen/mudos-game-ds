#include <ansi.h>
inherit ROOM;

void create()
{
set("short","�R�����p��");
        set("long", @LONG
al7..............�ȵL�ԭz
LONG
        );
        set("exits", ([
     "east":__DIR__"al6",
     "west":__DIR__"al8",
]));

        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
