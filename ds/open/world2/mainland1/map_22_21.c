inherit ROOM;
void create()
{
	set("short", "產業道路");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_22_20",
	"south" : __DIR__"map_23_21",
	"north" : __DIR__"map_21_21",
	"east" : __DIR__"map_22_22",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

