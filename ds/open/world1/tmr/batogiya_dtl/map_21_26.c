inherit ROOM;
void create()
{
	set("short", "民宅");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_20_26",
	]));
    set("objects", ([
        __DIR__"npc/xipi.c" : 1,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

