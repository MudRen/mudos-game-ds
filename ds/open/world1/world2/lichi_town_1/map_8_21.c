inherit ROOM;
void create()
{
	set("short", "水池邊");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_8_22",
	"south" : __DIR__"map_9_21",
	"north" : __DIR__"map_7_21",
	"west" : __DIR__"map_8_20",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

