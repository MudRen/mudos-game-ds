inherit ROOM;
void create()
{
	set("short", "石板路");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_4_13",
	"east" : __DIR__"map_3_14",
	"north" : __DIR__"map_2_13",
	"west" : __DIR__"map_3_12",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

