inherit ROOM;

void create()
{
set("short","小麥田");
        set("long", @LONG
這裡的氣候十分適合種值小麥，但是相對的這裡的農害也不少。你甚至
看到連稻草人上都站滿了麻雀，產生一幅十分諷刺的畫面。
LONG
        );
       set("exits", ([
        "northwest":__DIR__"f00",
        "east":__DIR__"f11",
        "southeast":__DIR__"f20",
]));
        set("objects", ([
        __DIR__"npc/sparrow" :3,
]));

        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

