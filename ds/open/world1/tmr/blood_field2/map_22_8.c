inherit ROOM;
void create()
{
	set("short", "草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_22_9",
	"west" : __DIR__"map_22_7",
	"south" : __DIR__"map_23_8",
	"north" : __DIR__"map_21_8",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

