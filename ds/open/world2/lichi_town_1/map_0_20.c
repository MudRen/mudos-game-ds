inherit ROOM;
void create()
{
	set("short", "梅龍鎮大門");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_1_20",
	"west" : __DIR__"map_0_19",
    "out" : "/open/world2/mainland1/map_25_15",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

