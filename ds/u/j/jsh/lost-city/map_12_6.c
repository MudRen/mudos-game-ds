inherit ROOM;
void create()
{
	set("short", "榕樹林");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_12_7",
	"west" : __DIR__"map_12_5",
	"south" : __DIR__"map_13_6",
	"north" : __DIR__"map_11_6",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

