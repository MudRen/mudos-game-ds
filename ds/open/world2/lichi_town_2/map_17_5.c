inherit ROOM;
void create()
{
	set("short", "樹上");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_17_6",
	"south" : __DIR__"map_18_5",
	"west" : __DIR__"map_17_4",
	]));
	set("outdoors","land");

        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

