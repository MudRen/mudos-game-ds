inherit ROOM;
void create()
{
	set("short", "草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_32_1",
	"west" : __DIR__"map_33_0",
	"south" : __DIR__"map_34_1",
	"east" : __DIR__"map_33_2",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

