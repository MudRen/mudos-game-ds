inherit ROOM;
void create()
{
	set("short", "草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_14_16",
	"south" : __DIR__"map_15_17",
	"north" : __DIR__"map_13_17",
	"east" : __DIR__"map_14_18",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

