inherit ROOM;
void create()
{
	set("short", "樹上");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_12_2",
	"south" : __DIR__"map_13_1",
	"north" : __DIR__"map_11_1",
	]));
	set("outdoors","land");

        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

