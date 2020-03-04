#include <path.h>

inherit ROOM;

void create()
{
        set("short", "山道");
        set("long", @LONG
你走在頗為破舊的山道上，腳下的石板路搖搖晃晃的建構在山壁
之中，需得小心翼翼的行走，以防不慎摔至山谷中。你往北的方向望
去，可看到一座峻偉不凡的高山－凌雲峰。
LONG
        );
          set("world", "past");
        set("exits", ([ /* sizeof() == 3 */
                "southeast" : ACME_PAST"bonze/b11.c",
                "north" : __DIR__"hill2.c",
        ]));
          set("outdoors","forest");
        set("no_clean_up", 0);
        set("objects", ([
                __DIR__"npc/beggar.c" : 1,
                ]));


        setup();
        replace_program(ROOM);
}


