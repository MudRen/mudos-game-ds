inherit ROOM;
void create()
{
	set("short", "樹上");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_17_37",
	]));
	set("outdoors","land");

        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

