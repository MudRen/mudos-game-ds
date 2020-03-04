#include <ansi.h>
inherit ROOM;

void create()
{
set("short","愛門村廣場南");
        set("long", @LONG
這是愛門村廣場的南邊，再往南走就是麥田了，這附近開始有一些麻雀
在飛來飛去。麻雀是愛門村最大的禍害，每年都讓農夫為了趕麻雀而辛苦不
已。這裡東北邊有一間較大的農舍，那是愛門村村長的家。
LONG
        );
        set("exits", ([
     "north":__DIR__"al4",
     "west":__DIR__"al6",
     "southwest":__DIR__"f00",
]));
        set("objects", ([
        __DIR__"npc/sparrow" :2,
]));

        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

