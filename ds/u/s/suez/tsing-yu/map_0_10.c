inherit ROOM;
void create()
{
	set("short", "街道");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_0_11",
	"west" : __DIR__"map_0_9",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

