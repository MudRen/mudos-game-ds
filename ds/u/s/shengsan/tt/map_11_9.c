inherit ROOM;
void create()
{
	set("short", "草原");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_11_8",
	"east" : __DIR__"map_11_10",
	"north" : __DIR__"map_10_9",
	"south" : __DIR__"map_12_9",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

