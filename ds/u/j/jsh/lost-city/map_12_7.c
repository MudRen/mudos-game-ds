inherit ROOM;
void create()
{
	set("short", "榕樹林");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_12_8",
	"west" : __DIR__"map_12_6",
	"south" : __DIR__"map_13_7",
	"north" : __DIR__"map_11_7",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

