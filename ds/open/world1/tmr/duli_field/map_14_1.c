inherit ROOM;
void create()
{
	set("short", "荒野草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_14_0",
	"north" : __DIR__"map_13_1",
	"east" : __DIR__"map_14_2",
	"south" : __DIR__"map_15_1",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

