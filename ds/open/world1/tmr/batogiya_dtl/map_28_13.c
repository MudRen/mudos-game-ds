inherit ROOM;
void create()
{
	set("short", "石橋");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_28_12",
	"east" : __DIR__"map_28_14",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

