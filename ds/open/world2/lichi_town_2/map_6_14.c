inherit ROOM;
void create()
{
	set("short", "防具店");
        set("long", @LONG

LONG
);
	set("exits",([
    "east" : "/open/world2/lichi_town_1/map_6_15",
	"south" : __DIR__"map_7_14",
	"west" : __DIR__"map_6_13",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

