inherit ROOM;
void create()
{
	set("short", "民宅門口");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_4_6",
    "north" : "/open/world2/lichi_town_2/map_2_6",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

