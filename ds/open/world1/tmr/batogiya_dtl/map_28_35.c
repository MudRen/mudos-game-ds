inherit ROOM;
void create()
{
	set("short", "草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_29_35",
	"west" : __DIR__"map_28_34",
	"east" : __DIR__"map_28_36",
	]));
    set("objects", ([
        __DIR__"npc/bigsnake.c" : 3,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

