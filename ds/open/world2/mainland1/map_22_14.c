inherit ROOM;
void create()
{
	set("short", "樹林");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_22_13",
	"south" : __DIR__"map_23_14",
	"north" : __DIR__"map_21_14",
	"east" : __DIR__"map_22_15",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

