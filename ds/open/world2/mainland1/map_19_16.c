inherit ROOM;
void create()
{
	set("short", "產業道路");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_19_15",
	"south" : __DIR__"map_20_16",
	"north" : __DIR__"map_18_16",
	"east" : __DIR__"map_19_17",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

