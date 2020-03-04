// This is a room made by roommaker.

inherit ROOM;

void create()
{
        set("short", "牌室");
        set("long", "一個相當整齊乾淨的牌室，樸素幽雅、一點也嗅不出緊張的氣氛。\n");
        set("exits", ([
            "west" : __DIR__"big2room",
        ]));
        set("objects", ([
            "/obj/big2.c" : 1,
         ])); 
 set("item_desc", ([
 "黃" : "黃色",
 ]));
        set("light",1);
        setup();
        replace_program(ROOM);
}

