inherit ROOM;
void create()
{
	set("short", "道路");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_8_14",
	"east" : __DIR__"map_8_16",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

