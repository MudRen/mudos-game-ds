inherit ROOM;
void create()
{
        set("short", "薄霧 ");
        set("long", @LONG

LONG
);
        set("exits",([ 
        "southwest" : __DIR__"map_10_1",
        "northeast" : __DIR__"map_8_3",
        ]));
        set("no_recall",1);
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

