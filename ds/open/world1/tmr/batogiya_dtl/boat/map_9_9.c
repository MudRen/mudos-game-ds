inherit ROOM;
void create()
{
	set("short", "船上");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_9_10",
	"west" : __DIR__"map_9_8",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

