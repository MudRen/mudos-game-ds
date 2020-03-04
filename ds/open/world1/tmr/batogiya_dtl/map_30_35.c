inherit ROOM;
void create()
{
	set("short", "道路");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_31_35",
	"west" : __DIR__"map_30_34",
	"north" : __DIR__"map_29_35",
	"east" : __DIR__"map_30_36",
	]));
    set("objects", ([
        __DIR__"npc/moca.c" : 1,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

