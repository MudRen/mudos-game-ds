inherit ROOM;
void create()
{
	set("short", "走道");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_15_10",
	"east" : __DIR__"map_15_12",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

