inherit ROOM;
void create()
{
	set("short", "草原");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_9_3",
	"north" : __DIR__"map_8_2",
	"south" : __DIR__"map_10_2",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

