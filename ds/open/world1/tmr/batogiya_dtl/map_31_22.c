inherit ROOM;
void create()
{
	set("short", "道路");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_32_22",
	"west" : __DIR__"map_31_21",
	"north" : __DIR__"map_30_22",
	"east" : __DIR__"map_31_23",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

