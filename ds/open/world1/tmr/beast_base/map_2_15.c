inherit ROOM;
void create()
{
	set("short", "荒野-獸之徑");
        set("long", @LONG

LONG
);
set("move_direct", "south");

	set("exits",([
	"west" : __DIR__"map_2_14",
	"south" : __DIR__"map_3_15",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

