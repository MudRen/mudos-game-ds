#include <ansi.h>
inherit ROOM;

void create()
{
set("short","農舍");
        set("long", @LONG
這裡和一般的農家佈置沒有什麼兩樣，有一張低矮的木桌子和三個木製
椅子，手工略顯的有些粗拙。
LONG
        );
        set("exits", ([
        "east":__DIR__"al4",
]));
        set("objects", ([
        __DIR__"npc/farmer1" :1,
]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

