inherit ROOM;
void create()
{
	set("short", "岩漿");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_12_12",
	"east" : __DIR__"map_11_13",
	"north" : __DIR__"map_10_12",
	"west" : __DIR__"map_11_11",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

