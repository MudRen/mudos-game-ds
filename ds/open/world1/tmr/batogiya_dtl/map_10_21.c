inherit ROOM;
void create()
{
	set("short", "道路");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_11_21",
	"west" : __DIR__"map_10_20",
	"east" : __DIR__"map_10_22",
	]));
    set("objects", ([
        __DIR__"npc/villager.c" : 3,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

