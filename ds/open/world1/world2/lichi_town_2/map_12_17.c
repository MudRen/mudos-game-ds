inherit ROOM;
void create()
{
	set("short", "道具店");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_12_18",
	"south" : __DIR__"map_13_17",
	"west" : __DIR__"map_12_16",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

