inherit ROOM;
void create()
{
	set("short", "草原");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_11_15",
	"south" : __DIR__"map_12_16",
	"east" : __DIR__"map_11_17",
	"north" : __DIR__"map_10_16",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

