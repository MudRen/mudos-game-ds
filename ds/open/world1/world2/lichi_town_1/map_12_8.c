inherit ROOM;
void create()
{
	set("short", "黃梅公園");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_13_8",
	"north" : __DIR__"map_11_8",
	"west" : __DIR__"map_12_7",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

