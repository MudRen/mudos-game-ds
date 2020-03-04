        
inherit ROOM;

void create()
{
        set("short", "洞內盡頭");
        set("long", @LONG
這裡已經是山洞裡的盡頭，兩旁的岩壁已經剝落不少，地上有不少果
實的殘骸，似乎有動物居住在這裡。

LONG
);
        set("exits",([
        "south" : __DIR__"map_4_15",
        ]));
        set("outdoors","forest");
        set("objects",([
                 __DIR__"npc/bigfoxbear":1,
                  "/obj/stake":4,
        ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

