inherit ROOM;
void create()
{
	set("short", "榕樹林");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_11_15",
	"west" : __DIR__"map_11_13",
	"south" : __DIR__"map_12_14",
	"north" : __DIR__"map_10_14",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

