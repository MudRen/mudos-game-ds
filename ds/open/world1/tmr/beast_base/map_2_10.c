inherit ROOM;
void create()
{
	set("short", "荒野-獸之徑");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_2_9",
	"south" : __DIR__"map_3_10",
	"east" : __DIR__"map_2_11",
	"north" : __DIR__"map_1_10",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

