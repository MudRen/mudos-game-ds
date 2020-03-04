// Room25.c

inherit ROOM;

void create()
{
        set("short","天地會會議室");
        set("long", @LONG
這裡是內殿，正是天地會長老們會議之地，目下擺設極為簡單。
此處設有佈告板，通常幫會中各大小事務也在此公告，以供幫員聯絡
之用。往北可以到達神秘之間，往南可以到達天地會大殿。

LONG
        );
        set("exits", ([
                "north": __DIR__"room15",
                 "west": __DIR__"room50",
                "south": __DIR__"room35",
                 "east": __DIR__"room60",
        ]));
        set("objects", ([
                __DIR__"item/axe1" : 1,
        ]));
        set("light",1);
        set("no_kill",1);
set("no_goto",1);
        setup();
        set("stroom",1);
        call_other( "/obj/board/sky_room25_b", "???" );
}

