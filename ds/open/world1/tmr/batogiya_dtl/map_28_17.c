inherit ROOM;
void create()
{
	set("short", "道路");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_29_17",
	"west" : __DIR__"map_28_16",
	]));
    set("objects", ([
        __DIR__"npc/man.c" : 4,
    ]));

        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

