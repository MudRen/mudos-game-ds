inherit ROOM;
void create()
{
	set("short", "荒島上的小路");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_9_14",
	"west" : __DIR__"map_10_13",
	"east" : __DIR__"map_10_15",
	"south" : __DIR__"map_11_14",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

