inherit ROOM;
void create()
{
	set("short", "荒野草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_5_16",
	"north" : __DIR__"map_4_17",
	"east" : __DIR__"map_5_18",
	"south" : __DIR__"map_6_17",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

