inherit ROOM;
void create()
{
	set("short", "診所入口");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_1_36",
    "south" : "/open/world2/lichi_town_2/map_3_36",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

