inherit ROOM;
void create()
{
	set("short", "草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_32_6",
	"west" : __DIR__"map_31_5",
	"north" : __DIR__"map_30_6",
	]));
    set("objects", ([
        __DIR__"npc/obj/branche.c" : 1,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

