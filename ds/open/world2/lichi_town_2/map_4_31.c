inherit ROOM;
void create()
{
	set("short", "倉庫");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_4_32",
	"south" : __DIR__"map_5_31",
	"north" : __DIR__"map_3_31",
    "west" : "/open/world2/lichi_town_1/map_4_30",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

