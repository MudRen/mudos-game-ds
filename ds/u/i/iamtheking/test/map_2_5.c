inherit ROOM;
void create()
{
	set("short", "榕樹林");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_2_4",
	"north" : __DIR__"map_1_5",
	"south" : __DIR__"map_3_5",
	"east" : __DIR__"map_2_6",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

