inherit ROOM;
void create()
{
	set("short", "草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_8_20",
	"west" : __DIR__"map_9_19",
	"south" : __DIR__"map_10_20",
	"east" : __DIR__"map_9_21",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

