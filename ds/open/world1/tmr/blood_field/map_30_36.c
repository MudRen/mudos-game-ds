inherit ROOM;
void create()
{
	set("short", "草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_29_36",
	"west" : __DIR__"map_30_35",
	"south" : __DIR__"map_31_36",
	"east" : __DIR__"map_30_37",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

