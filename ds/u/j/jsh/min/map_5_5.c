inherit ROOM;
void create()
{
	set("short", "岩漿");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_6_5",
	"east" : __DIR__"map_5_6",
	"north" : __DIR__"map_4_5",
	"west" : __DIR__"map_5_4",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

