inherit ROOM;
void create()
{
	set("short", "岩漿");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_7_4",
	"east" : __DIR__"map_6_5",
	"north" : __DIR__"map_5_4",
	"west" : __DIR__"map_6_3",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

