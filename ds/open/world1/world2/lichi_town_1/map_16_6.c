inherit ROOM;
void create()
{
	set("short", "黃梅公園");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_16_7",
	"south" : __DIR__"map_17_6",
	"north" : __DIR__"map_15_6",
	"west" : __DIR__"map_16_5",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

