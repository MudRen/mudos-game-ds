inherit ROOM;
void create()
{
	set("short", "草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_16_16",
	"west" : __DIR__"map_16_14",
	"south" : __DIR__"map_17_15",
	"north" : __DIR__"map_15_15",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

