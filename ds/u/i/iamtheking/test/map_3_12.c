inherit ROOM;
void create()
{
	set("short", "石板路");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_3_11",
	"north" : __DIR__"map_2_12",
	"south" : __DIR__"map_4_12",
	"east" : __DIR__"map_3_13",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

