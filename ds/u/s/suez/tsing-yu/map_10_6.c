inherit ROOM;
void create()
{
	set("short", "街道");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_10_7",
	"south" : __DIR__"map_11_6",
	"north" : __DIR__"map_9_6",
	"west" : __DIR__"map_10_5",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

