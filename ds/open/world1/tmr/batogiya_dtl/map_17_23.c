inherit ROOM;
void create()
{
	set("short", "武器店");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_17_24",
	]));
    set("objects", ([
        __DIR__"npc/lipoluo.c" : 1,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

