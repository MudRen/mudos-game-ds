inherit ROOM;
void create()
{
	set("short", "石板路");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_3_10",
	"south" : __DIR__"map_4_11",
	"east" : __DIR__"map_3_12",
	"north" : __DIR__"map_2_11",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

