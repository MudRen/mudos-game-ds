inherit ROOM;
void create()
{
	set("short", "草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_29_18",
	"west" : __DIR__"map_30_17",
	"south" : __DIR__"map_31_18",
	"east" : __DIR__"map_30_19",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

