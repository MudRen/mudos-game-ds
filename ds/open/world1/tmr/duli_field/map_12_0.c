inherit ROOM;
void create()
{
	set("short", "荒野草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_11_0",
	"east" : __DIR__"map_12_1",
	"south" : __DIR__"map_13_0",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

