inherit ROOM;
void create()
{
	set("short", "血跡");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_8_2",
	"west" : __DIR__"map_8_0",
	"south" : __DIR__"map_9_1",
	"north" : __DIR__"map_7_1",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

