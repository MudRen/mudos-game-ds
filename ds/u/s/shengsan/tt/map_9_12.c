inherit ROOM;
void create()
{
	set("short", "榕樹林");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_9_11",
	"east" : __DIR__"map_9_13",
	"north" : __DIR__"map_8_12",
	"south" : __DIR__"map_10_12",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

