inherit ROOM;
void create()
{
	set("short", "道路");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_32_21",
	"west" : __DIR__"map_31_20",
	"north" : __DIR__"map_30_21",
	"east" : __DIR__"map_31_22",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

