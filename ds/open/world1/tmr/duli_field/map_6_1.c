inherit ROOM;
void create()
{
	set("short", "荒野草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_6_0",
	"north" : __DIR__"map_5_1",
	"east" : __DIR__"map_6_2",
	"south" : __DIR__"map_7_1",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

