inherit ROOM;
void create()
{
	set("short", "荒野-獸之徑");
        set("long", @LONG

LONG
);
set("move_direct", "south");

	set("exits",([
	"south" : __DIR__"map_11_15",
	"north" : __DIR__"map_9_15",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

