inherit ROOM;
void create()
{
	set("short", "草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_24_3",
	"west" : __DIR__"map_23_2",
	"north" : __DIR__"map_22_3",
	"east" : __DIR__"map_23_4",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

