inherit ROOM;
void create()
{
	set("short", "拱橋");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_7_13",
	"north" : __DIR__"map_6_14",
	"south" : __DIR__"map_8_14",
	"east" : __DIR__"map_7_15",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

