inherit ROOM;
void create()
{
	set("short", "走道");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_18_11",
	"east" : __DIR__"map_18_13",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

