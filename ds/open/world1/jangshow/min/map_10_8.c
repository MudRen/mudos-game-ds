inherit ROOM;
void create()
{
	set("short", "石板路");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_11_8",
	"east" : __DIR__"map_10_9",
	"north" : __DIR__"map_9_8",
	"west" : __DIR__"map_10_7",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

