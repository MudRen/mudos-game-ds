inherit ROOM;
void create()
{
	set("short", "民房");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_9_12",
	"south" : __DIR__"map_10_11",
	"west" : __DIR__"map_9_10",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

