inherit ROOM;
void create()
{
	set("short", "石板路");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_6_3",
	"west" : __DIR__"map_6_1",
	"south" : __DIR__"map_7_2",
	"north" : __DIR__"map_5_2",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

