inherit ROOM;
void create()
{
	set("short", "道路");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_14_6",
	"west" : __DIR__"map_13_5",
	"north" : __DIR__"map_12_6",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

