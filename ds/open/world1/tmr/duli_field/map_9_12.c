inherit ROOM;
void create()
{
	set("short", "廢棄的石路");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_9_11",
	"north" : __DIR__"map_8_12",
	"east" : __DIR__"map_9_13",
	"south" : __DIR__"map_10_12",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

